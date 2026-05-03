// 00542360 RGE_Game_World::load_game
// World.cpp:1111-1146, 259 bytes
//
// uchar __thiscall RGE_Game_World::load_game(char* param_1)
// ret 4 cleanup (1 stack param, this in ecx)
//
// === Attempt log ===
//
// 1: Initial version - 77.6% positional diff, wrong frame (0x138), wrong this register
// 2: Fixed buffer order (tempname before version) - this in ebp
// 3: Fixed class decl, goto comparison - 77.9%
// 4: Mini version exploring frame size source
// 5: Single buffer approach - 0x134 frame fixed!
// 6a: Individual byte comparison - prologue changed (this→esi)
// 6b: strcmp version - PROLOGUE MATCHES! (push ebx, push ebp, mov ebp,ecx, push esi, push edi)
//     strcmp gets inlined by VC5 into the exact 2-byte comparison loop with sbb result!
//     256 bytes vs 259 (3 bytes short)
// 7: Goto block ordering experiment - 240 bytes (worse)
//
// === Current status (6b) ===
//
// Matches:
// - Prologue: sub esp,0x134; mov [world_update_counter],0; push ebx,ebp; mov ebp,ecx; push esi,edi ✓
// - vtable dispatch: mov ebx,[ebp]; call [ebx+0xB8] / call [ebx+0xC8] ✓
// - sprintf, rge_open, rge_read calls ✓
// - Inline strcmp: 2-byte loop with sbb/sbb result pattern ✓
// - Return paths (3: fd==-1, version mismatch, success) ✓
// - Epilogue registers: pop edi,esi,ebp,ebx; add esp,0x134; ret 4 ✓
// - Frame size: 0x134 (308 bytes) ✓
//
// Remaining gap (3 bytes):
// - Block ordering: fd==-1 handler is inline (jne skip) instead of at end (je handler)
//   This is a VC5 block-ordering optimization decision (cold/hot path heuristic)
//   that requires full World.cpp TU context.
// - Relocation addresses will resolve at link time.

#include <stdio.h>
#include <string.h>

extern "C" int __cdecl rge_open(const char* path, int access);
extern "C" void __cdecl rge_read(int fd, void* buf, int size);
extern "C" int __cdecl rge_close(int fd);

extern int world_update_counter;
extern void* rge_base_game;
extern int save_game_version;

class RGE_Game_World {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();

    unsigned char load_game(char* param_1);
};

unsigned char RGE_Game_World::load_game(char* param_1)
{
    char buf[308];

    world_update_counter = 0;

    this->vfB8();

    sprintf(buf + 8, "%s%s",
        *(const char**)((char*)rge_base_game + 0x0C) + 0xB12,
        param_1);

    int fh = rge_open(buf + 8, 0x8000);
    if (fh == -1)
        return 0;

    rge_read(fh, buf, 8);
    rge_read(fh, &save_game_version, 4);

    if (strcmp(buf, "VER 8.6") != 0) {
        rge_close(fh);
        return 0;
    }

    this->vfC8();
    rge_close(fh);
    return 1;
}
