// 00541A80 RGE_Game_World::init_sprites(int param_1)
// Protected virtual, with EH frame — needs /GX flag
// Source: World.cpp lines 804-816
// Size: 216 bytes
//
// Status: exact candidate — locally validated under the pinned VC5 toolchain
//
// Attempt log:
// Probe 1: basic stub, no EH — 112 bytes (need 216)
// Probe 2: virtual ~RGE_Game_World() + /GX — EH frame but wrong order
//   push -1 first vs mov eax,fs:[0] first
//   extra push ecx (4-byte local)
//   wrong sizeof(RGE_Sprite) = 1 (needs 0x78 for operator new)
// Probe 3: fixed RGE_Sprite size to 0x78 — correct push 0x78
// Probe 4: virtual init_sprites decl — same prologue issue
// Probe 5: non-virtual init_sprites — same
// Probe 6: restructured for loops — same
// Current session probe 1 (baseline): current scratch source emitted 226 bytes;
// the minimal RGE_Game_World surface had the wrong field offsets and rehook arg.
// Current session probe 2 (layout): restored the polymorphic world surface and
// proven fields at +0x30/+0x34/+0x38/+0x64; size stayed 226 bytes.
// Current session probe 3 (behavior): rehook takes the sprite-array value, not
// &sprites; exact 216-byte match.
//
// Key findings:
// - /GX + operator new triggers C++ EH frame
// - RGE_Sprite size: 0x78 (needs dummy[0x78] for correct sizeof)
// - RGE_Game_World fields: sounds at +0x30, sprite_num at +0x34
//   (short), sprites at +0x38, color_tables at +0x64
// - rge_read signature: rge_read(int param_1, void* buf, int size)
// - calloc(count, size) for sprites array allocation
// - RGE_Sprite constructor: (int param_1, RGE_Sound**, RGE_Color_Table**)
// - RGE_Sprite::rehook takes sprites array as arg
// - Virtual destructor NOT needed for EH (virtual method sufficient)
//
// Resolved: the corrected rehook pointer level lets VC5 select the original EH,
// parameter-slot reuse, register allocation, and per-access member reloads.
// No inline asm; custom flags: /GX (required by the original EH frame).

#include "../../include/world_scenario_context.h"

void RGE_Game_World::init_sprites(int param_1)
{
    rge_read(param_1, &sprite_num, 2);

    sprites = (RGE_Sprite**)calloc(sprite_num, 4);

    rge_read(param_1, sprites, sprite_num * 4);

    for (int ii = 0; ii < sprite_num; ii++) {
        if (sprites[ii]) {
            sprites[ii] = new RGE_Sprite(param_1, sounds, color_tables);
        }
    }

    for (int j = 0; j < sprite_num; j++) {
        if (sprites[j]) {
            sprites[j]->rehook(sprites);
        }
    }
}
