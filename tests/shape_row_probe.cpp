// Execute extracted x86 decoder bodies. This is a test, not a source owner.
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Entry {
public:
    unsigned char color(void*, long, long, long, long, long, long, long,
                        unsigned char*);
    unsigned char dither(void*, long, long, long, long, long, long, long, long);
};

static long __fastcall pitch(void* area, void*)
{
    return *(long*)((unsigned char*)area + 0x20);
}

static void* load(FILE* file)
{
    unsigned long size, count, offset, target;
    if (fread(&size, 4, 1, file) != 1 || fread(&count, 4, 1, file) != 1)
        exit(2);
    unsigned char* code = (unsigned char*)VirtualAlloc(
        0, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!code || fread(code, 1, size, file) != size) exit(2);
    for (unsigned long i = 0; i < count; ++i) {
        if (fread(&offset, 4, 1, file) != 1 || fread(&target, 4, 1, file) != 1)
            exit(2);
        if (offset < 1 || offset + 4 > size || code[offset - 1] != 0xe8)
            exit(2);
        void* address = target == 0 ? (void*)pitch : (void*)memset;
        *(long*)(code + offset) = (unsigned char*)address - (code + offset + 4);
    }
    FlushInstructionCache(GetCurrentProcess(), code, size);
    return code;
}

static unsigned char invoke(void* code, int dither, void* shape, void* area,
                            int x, int y, int right, unsigned char* table)
{
    if (dither) {
        unsigned char (Entry::*method)(void*, long, long, long, long, long,
                                      long, long, long);
        if (sizeof(method) != sizeof(code)) exit(2);
        memcpy(&method, &code, sizeof(code));
        return (((Entry*)shape)->*method)(area, x, y, 0, 0, right, 1, 0, 0);
    }
    unsigned char (Entry::*method)(void*, long, long, long, long, long,
                                  long, long, unsigned char*);
    if (sizeof(method) != sizeof(code)) exit(2);
    memcpy(&method, &code, sizeof(code));
    return (((Entry*)shape)->*method)(area, x, y, 0, 0, 0, right, 1, table);
}

int main(int argc, char** argv)
{
    if (argc != 2) return 2;
    FILE* file = fopen(argv[1], "rb");
    if (!file) return 2;
    void* code[4];
    for (int i = 0; i < 4; ++i) code[i] = load(file);
    fclose(file);
    unsigned char surface[2][4096], stream[2][512], tables[2][256];
    unsigned char area[2][256], shape[2][32];
    int tests = 0, failures = 0;
    // Valid packets cover literal, fill, skip, empty, and mixed rows.
    // Each stream includes one extra row for vertical clipping.
    for (int dither = 0; dither < 2; ++dither)
    for (int orientation = -1; orientation <= 1; orientation += 2)
    for (int x = -2; x <= 0; x += 2)
    for (int y = -1; y <= 0; ++y)
    for (int right = 2; right <= 5; right += 3)
    for (int kind = 0; kind < 5; ++kind)
    for (int overlap = 0; overlap < 2; ++overlap) {
        memset(surface, 0xa5, sizeof(surface));
        memset(stream, 0, sizeof(stream));
        memset(area, 0, sizeof(area));
        memset(shape, 0, sizeof(shape));
        unsigned char result[2];
        for (int side = 0; side < 2; ++side) {
            unsigned char* p = stream[side] + 24;
            for (int row = 0; row < 3; ++row) {
                if (kind == 0) { // Six literal pixels.
                    *p++ = 13;
                    for (i = 0; i < 6; ++i) *p++ = (unsigned char)(7 + i + row);
                } else if (kind == 1) { // Six fill pixels.
                    *p++ = 12; *p++ = (unsigned char)(9 + row);
                } else if (kind == 2) { // Skip, then two literal pixels.
                    *p++ = 1; *p++ = 2; *p++ = 5; *p++ = 7; *p++ = 9;
                } else if (kind == 3) { // Two short runs across a clip edge.
                    *p++ = 5; *p++ = 7; *p++ = 9;
                    *p++ = 8; *p++ = 11;
                }
                *p++ = 0;
            }
            for (i = 0; i < 256; ++i) tables[side][i] = (unsigned char)i;
            unsigned char* table = overlap ? surface[side] + 512 : tables[side];
            if (overlap) memcpy(table, tables[side], 256);
            *(void**)(shape[side] + 12) = stream[side];
            *(void**)(area[side] + 8) = surface[side] + 512;
            *(long*)(area[side] + 0x1c) = 8;
            *(long*)(area[side] + 0x20) = 32;
            *(long*)(area[side] + 0x24) = orientation;
            result[side] = invoke(code[dither * 2 + side], dither,
                                  shape[side], area[side], x, y, right, table);
        }
        ++tests;
        if (result[0] != result[1] || memcmp(surface[0], surface[1], 4096) ||
            memcmp(stream[0], stream[1], 512) || memcmp(tables[0], tables[1], 256)) {
            ++failures;
            printf("FAIL dither=%d orientation=%d x=%d y=%d right=%d kind=%d overlap=%d\n",
                   dither, orientation, x, y, right, kind, overlap);
        }
    }
    printf("cases=%d failures=%d\n", tests, failures);
    for (i = 0; i < 4; ++i) VirtualFree(code[i], 0, MEM_RELEASE);
    return failures ? 1 : 0;
}
