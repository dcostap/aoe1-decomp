// 00542060 RGE_Game_World::load_player
// Source: World.cpp lines 1005-1017. 137 bytes. __thiscall, ret 0Ch.
// Has EH registration — needs /GX.

class RGE_Game_World;

class RGE_Player {
public:
    char gap_00[0x21C]; // +4 vtable = 0x220 total
    RGE_Player(int param_1, RGE_Game_World* world, short param_3);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    void** players; // +0x40

    void load_player(int param_1, unsigned char param_2, short param_3);
};

// Class with vtable matching RGE_Player's layout (29th vtable entry at offset 0x74)
class PlayerVTable {
public:
    virtual void d00(); virtual void d01(); virtual void d02();
    virtual void d03(); virtual void d04(); virtual void d05();
    virtual void d06(); virtual void d07(); virtual void d08();
    virtual void d09(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17();
    virtual void d18(); virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26();
    virtual void d27(); virtual void d28();
    virtual void vfunc(int param); // vtable[29] = offset 0x74
};

void RGE_Game_World::load_player(int param_1, unsigned char param_2, short param_3) {
    if (param_2 != 0)
        return;

    RGE_Player* player = new RGE_Player(param_1, this, param_3);
    this->players[param_3] = (void**)player;
    ((PlayerVTable*)player)->vfunc(param_1);
}
