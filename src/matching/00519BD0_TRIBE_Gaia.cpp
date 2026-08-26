// VA: 00519BD0 TRIBE_Gaia::TRIBE_Gaia(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char)
// PDB source: tplayer.cpp lines 5275-5282
// Match: 101/101 bytes, 0.0000%

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Master_Player;
class RGE_Game_World { char gap[4]; };

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    char gap_04[0x44];     // +0x04 to +0x47
    unsigned char field_48; // +0x48
    char gap_49[0x7FF];    // +0x49 to +0x847

    TRIBE_Player(RGE_Game_World* world, RGE_Master_Player* master,
                 unsigned char player_id, char* name, unsigned char civ,
                 unsigned char is_computer, unsigned char is_active,
                 char* ai1, char* ai2, char* ai3);
};

class TRIBE_World { char gap[4]; };

class TRIBE_Gaia : public TRIBE_Player {
public:
    int field_848;
    int field_84C;
    int field_850;
    int field_854;

    TRIBE_Gaia(TRIBE_World* world, RGE_Master_Player* player,
               unsigned char param_3, char* param_4, unsigned char param_5);
};
#endif

TRIBE_Gaia::TRIBE_Gaia(TRIBE_World* world, RGE_Master_Player* player,
                        unsigned char param_3, char* param_4, unsigned char param_5)
    : TRIBE_Player((RGE_Game_World*)world, player, param_3, param_4, param_5, 0, 1, 0, 0, 0)
{
    this->field_48 = 2;
    this->field_848 = 0;
    this->field_84C = 0x1D;
    this->field_854 = 0;
    this->field_850 = 0;
}
