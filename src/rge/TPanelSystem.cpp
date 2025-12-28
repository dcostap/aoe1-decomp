#include "TPanelSystem.h"
#include "RESFILE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to read palette
// Address: 0x00444A00 (approx)
void *ReadPalette(const char *name, int id, int flag) {
#ifdef _DEBUG
    printf("ReadPalette: name=%s id=%d\n", name ? name : "NULL", id);
#endif
    int size = 0;
    int out_flag = 0;
    uchar *data = RESFILE_load(0x62696e61, id, &size, &out_flag); // 'bina'
    
    if (!data) {
#ifdef _DEBUG
        printf("ReadPalette: Not in DRS, trying file...\n");
#endif
        // Try loading from file if not in DRS
        FILE *f = fopen(name, "rb");
        if (!f) {
#ifdef _DEBUG
            printf("ReadPalette: File not found: %s\n", name);
#endif
            return nullptr;
        }
        fseek(f, 0, SEEK_END);
        size = ftell(f);
        fseek(f, 0, SEEK_SET);
        data = (uchar *)malloc(size);
        fread(data, 1, size, f);
        fclose(f);
        out_flag = 1;
    }

    if (!data) return nullptr;

    // Create a null-terminated copy for string parsing
    char *data_copy = (char *)malloc(size + 1);
    memcpy(data_copy, data, size);
    data_copy[size] = '\0';

    LOGPALETTE *lp = nullptr;
    char *ctx = nullptr;
    char *line = strtok_s(data_copy, "\r\n", &ctx);
    if (line && strcmp(line, "JASC-PAL") == 0) {
        strtok_s(nullptr, "\r\n", &ctx); // 0100
        line = strtok_s(nullptr, "\r\n", &ctx); // 256
        int num_entries = line ? atoi(line) : 0;
        if (num_entries > 0) {
            lp = (LOGPALETTE *)malloc(sizeof(LOGPALETTE) + (num_entries - 1) * sizeof(PALETTEENTRY));
            lp->palVersion = 0x300;
            lp->palNumEntries = (WORD)num_entries;
            for (int i = 0; i < num_entries; i++) {
                line = strtok_s(nullptr, "\r\n", &ctx);
                if (line) {
                    int r, g, b;
                    if (sscanf(line, "%d %d %d", &r, &g, &b) == 3) {
                        lp->palPalEntry[i].peRed = (BYTE)r;
                        lp->palPalEntry[i].peGreen = (BYTE)g;
                        lp->palPalEntry[i].peBlue = (BYTE)b;
                        lp->palPalEntry[i].peFlags = 0;
                    }
                }
            }
        }
    } else {
        // Binary palette? (256 * 4 bytes or similar)
        if (size >= 1024) {
            lp = (LOGPALETTE *)malloc(sizeof(LOGPALETTE) + 255 * sizeof(PALETTEENTRY));
            lp->palVersion = 0x300;
            lp->palNumEntries = 256;
            memcpy(lp->palPalEntry, data, 1024);
        }
    }

    free(data_copy);
    if (out_flag == 1) free(data);
    return lp;
}

TPanelSystem::TPanelSystem() {
    memset(this, 0, sizeof(TPanelSystem));
    for (int i = 0; i < 10; i++) {
        this->palette_id[i] = -1;
    }
}

void TPanelSystem::release_palette(TPanelSystem *ps, void *pal) {
    if (!ps || !pal) return;
    for (int i = 0; i < 10; i++) {
        if (ps->palette[i] == pal) {
            ps->palette_use_count[i]--;
            if (ps->palette_use_count[i] <= 0) {
                free(ps->palette[i]);
                ps->palette[i] = nullptr;
                ps->palette_id[i] = -1;
                ps->palette_file[i][0] = '\0';
            }
            return;
        }
    }
}

void *TPanelSystem::get_palette(TPanelSystem *ps, const char *pal_file, int id) {
    if (!ps) return nullptr;

    char full_name[260];
    if (pal_file) {
        if (strchr(pal_file, '.')) {
            strcpy(full_name, pal_file);
        } else {
            sprintf(full_name, "%s.pal", pal_file);
        }
        _strupr(full_name);
    } else {
        full_name[0] = '\0';
    }

    // Check if already loaded
    for (int i = 0; i < 10; i++) {
        if (ps->palette[i]) {
            if (id != -1 && ps->palette_id[i] == id) {
                ps->palette_use_count[i]++;
                return ps->palette[i];
            }
            if (full_name[0] && strcmp(ps->palette_file[i], full_name) == 0) {
                ps->palette_use_count[i]++;
                return ps->palette[i];
            }
        }
    }

    // Find empty slot
    int slot = -1;
    for (int i = 0; i < 10; i++) {
        if (!ps->palette[i]) {
            slot = i;
            break;
        }
    }

    if (slot == -1) return nullptr;

    void *pal = ReadPalette(full_name, id, 1);
    if (!pal && id == 50500) {
#ifdef _DEBUG
        printf("TPanelSystem::get_palette: 50500 failed, trying 50501...\n");
#endif
        pal = ReadPalette(full_name, 50501, 1);
    }

    if (pal) {
#ifdef _DEBUG
        printf("TPanelSystem::get_palette: Successfully loaded palette %d\n", id);
#endif
        ps->palette[slot] = pal;
        ps->palette_id[slot] = id;
        if (full_name[0]) strcpy(ps->palette_file[slot], full_name);
        ps->palette_use_count[slot] = 1;
    } else {
#ifdef _DEBUG
        printf("TPanelSystem::get_palette: Failed to load palette %s (id %d)\n", full_name, id);
#endif
    }

    return pal;
}

void TPanelSystem::setCurrentPanel(TPanelSystem *ps, const char *name, int id) {}
void TPanelSystem::destroyPanel(TPanelSystem *ps, const char *name) {}
void *TPanelSystem::panel(TPanelSystem *ps, const char *name) { return nullptr; }
