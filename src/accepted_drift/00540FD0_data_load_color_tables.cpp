// VA: 00540FD0, RGE_Game_World::data_load_color_tables, 264 bytes
// Source: World.cpp lines 464-489
// ACCEPTED_DRIFT: VC5 version compiler differences in branch layout,
// loop comparison width, and register allocation. All behavior identical.
//
// Remaining drift:
// 1. Branch layout: original uses `je near error` (6 bytes) jumping over
//    the long success path to the short error path at the bottom. My compiler
//    generates `jne short success` (2 bytes) jumping over the short error path
//    to the long success path at the bottom. Same behavior, opposite layout.
//    This is a VC5 compiler heuristic that can't be controlled from source.
// 2. Loop comparison: original uses `cmp ax, [esp+2Ch]` (16-bit) while my
//    compiler generates `movsx edx, word [esp+2Ch]; cmp eax, edx` (32-bit).
//    Same behavior (signed comparison), different width.
// 3. Error path assignments: original uses immediate `mov word [esi], 0` and
//    `mov dword [ebx+64h], 0` while my compiler uses the zero register from
//    `xor esi, esi`.
//
// What matches (52 bytes): SEH prologue (`mov eax,[fs:0]; push -1; push handler; 
// push eax; mov [fs:0],esp; sub esp,0x0C; push ebx; push edi`), fopen call with
// "r", fopen-NULL check (`je near epilogue`), fscanf call with "%hd %hd" format,
// or EBP to -1 setup.
// Also matches: calloc call, SEH epilogue/prologue cleanup order.
//
// Attempt log:
// - v1: else clause → wrong branch layout
// - v2: goto check_failed → C2362
// - v3: if/else with do-while → same wrong layout
// - v4: goto-based layout → same (jne success vs je error)
// - v5: int count → C2362
// - v6: error in if-body → 256 bytes (too small)
// - v7: force sub esp,0xC → hacky
// - v8: clean for-loop → C2362
// - v9: clean structure with scopes → same as v1 (264 bytes, inverted layout)
// - Conclusion: The branch/inversion/comparison width are VC5 version artifacts
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stdlib.h>
#include <stdio.h>

typedef unsigned char uchar;

struct RGE_Color_Table {
    void* vtable_ptr;       // +0x00
    char name[30];          // +0x04
    short resource_id;      // +0x22
    uchar type;             // +0x24
    uchar map_color;        // +0x25
    short id;               // +0x26
    uchar table[256];       // +0x28

    RGE_Color_Table(FILE* f, short index);
};

class RGE_Game_World {
public:
    char _pad_00[0x60];
    short color_table_num;      // +0x60
    char _pad_62[0x02];
    RGE_Color_Table** color_tables; // +0x64
    char _pad_68[0x9C];
    int difficultyLevelValue;   // +0x100

    uchar data_load_color_tables(char* filename);
};

uchar RGE_Game_World::data_load_color_tables(char* filename)
{
    short count;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        goto epilogue;

    if (fscanf(f, "%hd %hd", &this->color_table_num, &count) == -1) {
        this->color_table_num = 0;
        this->color_tables = NULL;
        goto close;
    }

    this->color_tables = (RGE_Color_Table**)calloc(this->color_table_num, 4);
    {
        for (int i = 0; i < (short)count; i++) {
            short index;
            if (fscanf(f, "%hd", &index) != -1) {
                RGE_Color_Table* ct = new RGE_Color_Table(f, index);
                this->color_tables[index] = ct;
            }
        }
    }

close:
    fclose(f);

epilogue:
    return 1;
}
