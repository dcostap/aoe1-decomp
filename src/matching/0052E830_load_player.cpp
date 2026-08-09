// VA: 0052E830 TRIBE_World::load_player
// PDB source: tworld.cpp lines 328-344
//
// Baseline reconstruction: player slots are the RGE world array at +0x40;
// types 1 and 3 load TRIBE_Player, type 2 loads TRIBE_Gaia, and all other
// types defer to RGE_Game_World.  The final call is TRIBE_Player::load at
// vtable slot 0x74.  The class sizes are the proven 0x848/0x858 allocation
// sizes, rather than decompiler cursor arithmetic.

class TRIBE_World;

class RGE_Game_World {
public:
    virtual void v0();
    char gap_04[0x3C];
    void** players; // +0x40

    virtual void load_player(int player, unsigned char type, short player_id);
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void load(int player);

    char gap_04[0x844];
    TRIBE_Player(int file, TRIBE_World* world, unsigned char player_id);
};

class TRIBE_Gaia : public TRIBE_Player {
public:
    char gap_848[0x10];
    TRIBE_Gaia(int file, TRIBE_World* world, unsigned char player_id);
};

class TRIBE_World : public RGE_Game_World {
public:
    virtual void load_player(int player, unsigned char type, short player_id);
};

void TRIBE_World::load_player(int player, unsigned char type, short player_id)
{
    switch (type) {
    case 1:
    case 3:
        this->players[player_id] = new TRIBE_Player(player, this, (unsigned char)player_id);
        break;
    case 2:
        this->players[player_id] = new TRIBE_Gaia(player, this, (unsigned char)player_id);
        break;
    default:
        RGE_Game_World::load_player(player, type, player_id);
        return;
    }

    ((TRIBE_Player*)this->players[player_id])->load(player);
}
