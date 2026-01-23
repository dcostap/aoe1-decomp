#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include "../include/Res_file.h"
#include "../include/custom_debug.h"

// TODO: Move these to a common header if needed elsewhere
void CreateIdentityPalette(void* pal);

/**
 * Parses a JASC-PAL color line (three space-separated integers)
 */
static bool parse_pal_line(char* line, BYTE* r, BYTE* g, BYTE* b) {
    char* p = line;
    while (*p && (*p == ' ' || *p == '\t')) p++;
    if (!*p) return false;
    *r = (BYTE)atoi(p);
    
    while (*p && *p != ' ' && *p != '\t') p++;
    while (*p && (*p == ' ' || *p == '\t')) p++;
    if (!*p) return false;
    *g = (BYTE)atoi(p);
    
    while (*p && *p != ' ' && *p != '\t') p++;
    while (*p && (*p == ' ' || *p == '\t')) p++;
    if (!*p) return false;
    *b = (BYTE)atoi(p);
    
    return true;
}

/**
 * Loads a palette from a file or resource.
 * Supports JASC-PAL text format.
 */
void* ReadPalette(char* filename, long resource_id, int flag) {
    unsigned char* data = nullptr;
    int size = 0;
    int out_type = 0;
    bool own_mem = false;

    // 1. Try loading from file first
    if (filename && filename[0] != '\0') {
        int fd = _open(filename, _O_RDONLY | _O_BINARY);
        if (fd != -1) {
            long fileSize = _lseek(fd, 0, SEEK_END);
            _lseek(fd, 0, SEEK_SET);
            data = (unsigned char*)malloc(fileSize + 1);
            if (data) {
                _read(fd, data, fileSize);
                data[fileSize] = '\0';
                size = fileSize;
                own_mem = true;
            }
            _close(fd);
        }
    }

    // 2. Try loading from resource if file failed or resource_id is specified
    if (!data && resource_id != -1) {
        // ASM uses 'bina' (0x62696e61) tag for palette resources (see Dib.cpp.asm line 2116)
        data = RESFILE_load(0x62696e61, resource_id, &size, &out_type);
        if (data) {
            // If RESFILE_load returned mapped memory, we might need a copy to null-terminate for strtok
            if (out_type == 0) {
                unsigned char* copy = (unsigned char*)malloc(size + 1);
                if (copy) {
                    memcpy(copy, data, size);
                    copy[size] = '\0';
                    data = copy;
                    own_mem = true;
                }
            } else {
                // If it's already a malloc'd buffer, we still need to ensure space for null termination
                // but RESFILE_load doesn't guarantee that. Let's just assume text parsing works or realloc.
                // For safety, let's always work with a null-terminated copy if we suspect text format.
                unsigned char* copy = (unsigned char*)malloc(size + 1);
                if (copy) {
                    memcpy(copy, data, size);
                    copy[size] = '\0';
                    free(data); // Free the one from RESFILE_load
                    data = copy;
                    own_mem = true;
                }
            }
        }
    }

    if (!data) {
        CUSTOM_DEBUG_LOG_FMT("ReadPalette: failed to load '%s' / id %d", filename ? filename : "(null)", (int)resource_id);
        return nullptr;
    }

    HPALETTE hPal = nullptr;

    // Check for "JASC-PAL" header
    if (strncmp((char*)data, "JASC-PAL", 8) == 0) {
        CUSTOM_DEBUG_LOG_FMT("ReadPalette: parsing JASC-PAL '%s' / id %d", filename ? filename : "(null)", (int)resource_id);
		CUSTOM_DEBUG_LOG_FMT("ReadPalette: raw header: %.20s", (char*)data);
        // Parse JASC-PAL format
        // Line 1: JASC-PAL
        // Line 2: 0100 (version)
        // Line 3: Number of colors
        // Rest: R G B lines
        char* ctx = nullptr;
        char* line = strtok_s((char*)data, "\r\n", &ctx); // JASC-PAL
        line = strtok_s(nullptr, "\r\n", &ctx); // 0100
        line = strtok_s(nullptr, "\r\n", &ctx); // Count
        
        if (line) {
            int numColors = atoi(line);
            if (numColors > 0 && numColors <= 256) {
                LOGPALETTE* lp = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + (numColors * sizeof(PALETTEENTRY)));
                if (lp) {
                    lp->palVersion = 0x300;
                    lp->palNumEntries = (WORD)numColors;
                    
                    for (int i = 0; i < numColors; ++i) {
                        line = strtok_s(nullptr, "\r\n", &ctx);
                        if (line) {
                            parse_pal_line(line, &lp->palPalEntry[i].peRed, &lp->palPalEntry[i].peGreen, &lp->palPalEntry[i].peBlue);
                            lp->palPalEntry[i].peFlags = 0;
                        }
                    }
                    
                    hPal = CreatePalette(lp);
                    free(lp);
                }
            }
        }
    }

    if (own_mem) free(data);

    if (hPal && flag) {
        // CreateIdentityPalette(hPal);
    }

    return hPal;
}

/**
 * Ensures the palette is "identity", meaning it doesn't cause system color mapping issues
 * in 256-color modes. It copies system colors 0-9 and 246-255.
 */
void CreateIdentityPalette(void* pal) {
    HPALETTE hPal = (HPALETTE)pal;
    if (!hPal) return;

    PALETTEENTRY sysEntries[256];
    HDC hdc = GetDC(NULL);
    GetSystemPaletteEntries(hdc, 0, 256, sysEntries);
    ReleaseDC(NULL, hdc);

    // Identity palette logic:
    // We want the system to avoid remapping our palette indices if possible.
    // Usually involves setting peFlags to PC_NOCOLLAPSE or matching system static colors.
    
    // ASM seems to do some complex mapping. For now, we'll use a standard approach:
    // Copy the 20 system static colors into our palette.
    SetPaletteEntries(hPal, 0, 10, &sysEntries[0]);
    SetPaletteEntries(hPal, 246, 10, &sysEntries[246]);
}
