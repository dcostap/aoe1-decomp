// 00435BB0 RGE_Command::command_create_group (153B)
// Command.cpp:1774-1800
// ACCEPTED_DRIFT 2026-05-19: approved localized copy-loop delta optimization drift.
// VC5 emits sub+[eax+ecx] instead of separate add-eax/add-ecx pointer increments.
// Same behavior, calls, field offsets, and epilogue; only 10 positional bytes / 6.5%.
// VC5 subtraction optimization: uses sub+[eax+ecx] instead of separate add pointer increments
// Register swap: src in eax(orig) vs ecx(rebuilt)
// Attempts: 15+ across all documented VC5 axes
// - #define addresses for strings/globals ✓
// - virtual destructor for vtable ✓
// - void*/char* pointer arithmetic to break aliasing ✓
// - separate inner/outer counters ✓
// - block-scoped locals ✓
// - pointer-explicit casts ✓
// - all loop forms (do-while, for, while) ✓
// - indexed vs pointer loops ✓
// - separated src/dst incrementation via (char*)s+4 casts ✓

#include <stdlib.h>   // calloc

#define STR_SEND_CMD_CRT_GROUP ((const char*)0x00583D74)
#define STR_X                 ((const char*)0x00583B74)
#define PTR_L                 ((void*)0x0062C4FC)

#ifndef COMMAND_TU_CONTEXT
class RGE_Game_World;
class RGE_Static_Object;

class RGE_Command {
public:
    virtual ~RGE_Command() {}
    RGE_Game_World* world;      // +0x04

    void command_create_group(int p1, int p2, int* p3, int p4, int p5);
    void submit(void* buf, int size);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    char pad_00[0x08];
    void* field_08;
};
#endif

void __cdecl RGE_Log(void* log, const char* fmt, int count, int player, const char* name);

void RGE_Command::command_create_group(int p1, int p2, int* p3, int p4, int p5)
{
    char* buf = (char*)calloc(1, 0x74);
    int count = p4;

    buf[0] = 8;
    buf[1] = (char)p1;
    *(int*)(buf + 4) = p2;

    if (count > 0) {
        int* d = (int*)(buf + 0x0C);
        int* s = p3;
        int cnt = count;
        do {
            *d = *s;
            d++;
            s++;
        } while (--cnt);
    }

    buf[0x70] = (char)count;
    *(int*)(buf + 8) = p5;

    int first_id = p3[0];
    RGE_Static_Object* obj = this->world->object(first_id);
    const char* name;
    if (obj != 0) {
        name = *(const char**)((char*)obj->field_08 + 8);
    } else {
        name = STR_X;
    }
    RGE_Log(*(void**)PTR_L, STR_SEND_CMD_CRT_GROUP, count, p1, name);
    this->submit(buf, 0x74);
}
