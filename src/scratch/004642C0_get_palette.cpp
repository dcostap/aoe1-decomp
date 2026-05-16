// 004642C0 TPanelSystem::get_palette
// Panel.cpp:490-532 (155 asm lines, 443 bytes)
//
// Status: BLOCKED — multi-axis VC5 codegen basin mismatch.
// Best result: 26 matching prologue bytes (5.9%), edit diff 30.9%.
// Axes probed: prologue ordering, strcmp call vs inline, palette access pattern,
// strupr placement, saved_this pattern, param_1 branch direction.
// Attempts: ~16 manual + 8 variant lab combinations.
//
// Key insights from best variant:
// - Correct prologue (sub esp, 10Ch, push 4 regs, param_1 in EDI, this in EBX,
//   saved_this at [esp+14h]) requires: NO file_name[0..3] init,
//   `if (param_1) { ... } else { file_name[0]=0; }` structure,
//   `*(void**)((char*)id_i - 0xA78)` for palette[i] access,
//   and `strcmp()` call (not inline byte comparison).
//
// Remaining blockers:
// 1. Inline strcmp with 2-byte unrolling and BL/CL byte temps is irreproducible
//    from C source without affecting prologue layout. The call to strcmp()
//    avoids the inline loop but doesn't match the original's specific byte
//    comparison pattern (mov bl,[eax]; mov cl,bl; cmp bl,[esi]; ...).
// 2. Branch targets differ by ~1-2 bytes throughout due to size differences
//    between call vs inline code.
// 3. The `strupr()` call placement affects branch offsets — matching the
//    original's exact if-else layout is fragile.
// 4. Extra code in sprintf path (lea/structure adjustments).
//
// LEFT IN SCRATCH: structural codegen gap unlikely to yield exact match
// without significantly different source decomposition.

#include <string.h>
#include <stdio.h>

extern "C" void* __cdecl ReadPalette(char*, long, int);

class TPanelSystem_004642C0 {
public:
    char _0[0x1C];
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    long palette_id[10];

    void* get_palette(char* param_1, long param_2);
};

void* TPanelSystem_004642C0::get_palette(char* param_1, long param_2)
{
    char file_name[260];

    if (param_1) {
        if (strchr(param_1, '.') == 0) {
            sprintf(file_name + 4, "%s.pal", param_1);
        } else {
            strcpy(file_name, param_1);
        }
        strupr(file_name);
    } else {
        file_name[0] = 0;
    }

    int found = -1;
    long* id_i = this->palette_id;
    int i;
    char* file_i = (char*)this->palette_file;

    for (i = 0; i < 10; i++) {
        if (*(void**)((char*)id_i - 0xA78) == 0) {
            if (found == -1) found = i;
        } else {
            if (param_2 != -1 && *id_i == param_2) {
                this->palette_use_count[i]++;
                return this->palette[i];
            }

            if (strcmp(file_i, file_name) == 0) {
                this->palette_use_count[i]++;
                return this->palette[i];
            }
        }
        file_i += 260;
        id_i++;
    }

    if (found == -1) return 0;

    this->palette[found] = ReadPalette(file_name, param_2, 1);
    if (this->palette[found] == 0) return 0;

    this->palette_use_count[found]++;
    strcpy(this->palette_file[found], file_name);
    this->palette_id[found] = param_2;
    return this->palette[found];
}
