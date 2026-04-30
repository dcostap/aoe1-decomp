// 00541A80 RGE_Game_World::init_sprites(int param_1)
// Protected virtual, with EH frame — needs /GX flag
// Source: World.cpp lines 804-816
// Size: 216 bytes
//
// Status: PARKED — VC5 EH prologue ordering / register allocation drift
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
// Remaining drift (VC5 TU-context):
// - EH prologue: push -1; push handler; mov eax,fs:[0]; push eax
//   vs original: mov eax,fs:[0]; push -1; push handler; push eax
// - Extra push ecx (4-byte local) vs original reuses param_1 stack slot
// - Register allocation: edi=this, ebp=&sprite_num, esi=&sprites
//   vs original: esi=this, ebx=&sprite_num, ebp=param_1
// - Cached &sprites pointer vs per-access reload from [esi+38h]
// No inline asm, custom flags: /GX

#include <stddef.h>
#include <stdlib.h>

void* operator new(size_t size);

struct RGE_Sound;
struct RGE_Color_Table;

struct RGE_Sprite {
    char dummy[0x78];

    void rehook(RGE_Sprite*** sprites_array);
    RGE_Sprite(int param_1, RGE_Sound** sounds, RGE_Color_Table** color_tables);
};

void rge_read(int param_1, void* buf, int size);

void* calloc(int count, int size);

class RGE_Game_World {
public:
    char pad_00[0x30 - 4];
    RGE_Sound** sounds;         // +0x30
    short sprite_num;           // +0x34
    char pad_36[2];             // +0x36
    RGE_Sprite** sprites;       // +0x38
    char pad_3C[0x64 - 0x3C];
    RGE_Color_Table** color_tables; // +0x64

    void init_sprites(int param_1);
};

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
            sprites[j]->rehook(&sprites);
        }
    }
}
