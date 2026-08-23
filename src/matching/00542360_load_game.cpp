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
// 8: Outer `fh != -1` guard - restores the original late fd-failure block;
//    this is the same natural VC5 source shape proven by World.cpp donors.
// 9: Restored the slot-0xC8 load_world(int) ABI from the class reference; the
//    fd argument is shared before the version branch by the two call arms.
//
// === Current status (probe 9) ===
//
// Matches:
// - Prologue: sub esp,0x134; mov [world_update_counter],0; push ebx,ebp; mov ebp,ecx; push esi,edi ✓
// - vtable dispatch: mov ebx,[ebp]; call [ebx+0xB8] / load_world(fh) at [ebx+0xC8] ✓
// - sprintf, rge_open, rge_read calls ✓
// - Inline strcmp: 2-byte loop with sbb/sbb result pattern ✓
// - Return paths (3: fd==-1, version mismatch, success) ✓
// - Epilogue registers: pop edi,esi,ebp,ebx; add esp,0x134; ret 4 ✓
// - Frame size: 0x134 (308 bytes) ✓
// - Exact checker result: MATCH (0.0000%), 259/259 bytes; default flags.
// - The PDB names two adjacent arrays, but separate-array declarations add a
//   compiler-inserted four-byte stack gap. The contiguous 308-byte local keeps
//   the proven version/tempname anchors and is the clean exact reconstruction.
// - Main-agent audit restored the canonical base/world destructor and named
//   del_game_info surfaces; emitted code remains exact.

#include <string.h>
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::load_game(char* param_1)
{
    char buf[308];

    world_update_counter = 0;

    this->del_game_info();

    sprintf(buf + 8, "%s%s", rge_base_game->save_prog_info->save_dir, param_1);

    int fh = rge_open(buf + 8, 0x8000);
    if (fh != -1) {
        rge_read(fh, buf, 8);
        rge_read(fh, &save_game_version, 4);

        if (strcmp(buf, "VER 8.6") != 0) {
            rge_close(fh);
            return 0;
        }

        this->load_world(fh);
        rge_close(fh);
        return 1;
    }
    return 0;
}
