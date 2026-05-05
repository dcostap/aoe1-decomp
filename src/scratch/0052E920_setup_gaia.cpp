// 0052E920 TRIBE_World::setup_gaia()
// Source: tworld.cpp lines 348-351
// Size: 102 bytes, 33 asm lines

// 6+ attempts. Same EH epilogue codegen basin as 00471C90, 00519490.
// Size fixed: TRIBE_Gaia is 0x858 bytes (TRIBE_Player + 4 int fields).
// Remaining 21.6% diff: shared common epilogue (original) vs split-path
// epilogue (rebuilt). Not fixable from C++ source with this VC5 version.
// String/handler addresses are relocations masked by the tool.

class RGE_Master_Player {
public:
    void* vtable;
};

class RGE_Game_World {
public:
    char pad_00[0x40];
    void** players;
    char pad_44[0x4];
    void** master_players;

    void setup_gaia();
};

class TRIBE_World : public RGE_Game_World {
};

class TRIBE_Gaia {
public:
    char gap[0x858];

    TRIBE_Gaia(void* world, RGE_Master_Player* player,
               unsigned char param_3, const char* param_4, unsigned char param_5);
};

void RGE_Game_World::setup_gaia() {
    this->players[0] = new TRIBE_Gaia(this, (RGE_Master_Player*)this->master_players[0], 0, "GAIA", 0);
}
