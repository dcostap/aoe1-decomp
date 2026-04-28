// 005419E0 init_sounds (159 bytes) — MATCHED
// PDB: World.cpp (RGE_Game_World::init_sounds)
// protected virtual, __thiscall
// FLAGS: /GX (EH frame for new expression)

#include <stdlib.h>  // calloc

void rge_read(int param_1, void* param_2, int param_3);
void* __cdecl operator_new(size_t size);

class TSound_Driver;

class RGE_Sound {
public:
    // vtable (4 bytes) + 12 bytes data = 0x10 total
    RGE_Sound(int param_1, TSound_Driver* sound_driver);
    char gap_00[0x10];  // sizeof(RGE_Sound) = 0x10
};

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
    virtual void init_sounds(int param_1, TSound_Driver* param_2);

    char gap_04[0x28];
    short sound_num;                  // +0x2C
    RGE_Sound** sounds;               // +0x30
    char gap_34[0x80 - 0x34];
    TSound_Driver* sound_driver;      // +0x80
};

void RGE_Game_World::init_sounds(int param_1, TSound_Driver* param_2)
{
    rge_read(param_1, &this->sound_num, 2);
    this->sounds = (RGE_Sound**)calloc(this->sound_num, 4);
    for (int i = 0; i < this->sound_num; i++) {
        this->sounds[i] = new RGE_Sound(param_1, this->sound_driver);
    }
}
