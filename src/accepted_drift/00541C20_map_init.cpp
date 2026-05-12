// VA: 00541C20 RGE_Game_World::map_init
// PDB: World.cpp lines 831-833 (97 bytes, 30 asm lines)
// FLAGS: /GX required for original SEH frame — use config/flags/00541C20_map_init.rsp
// No inline asm/hacks.
// === ACCEPTED_DRIFT ===
// Same behavior-neutral VC5 no-op phi-merge artifact as accepted World/tworld init helpers:
// first 76 bytes exact, then dead `test eax,eax; jne +0` shifts final epilogue into padding.

class RGE_Game_World {
public:
    char gap_00[0x28];
    void* map;           // +0x28
    char gap_2C[4];      // +0x2C
    void* sounds;        // +0x30

    void map_init(int param_1, void* param_2);
};

class RGE_Map {
public:
    char gap[0x8DD0];

    RGE_Map(int param_1, void* sounds, int param_2);
};

void RGE_Game_World::map_init(int param_1, void* param_2) {
    RGE_Map* new_map = new RGE_Map(param_1, this->sounds, 1);
    if (new_map == 0) {
        new_map = 0;
    }
    this->map = new_map;
}
