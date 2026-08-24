// The binary calls the slot-0x20 RGE_Player virtual for each non-self player.
// The canonical name is isNeutral; the old relation_to_player name was a
// decompiler artifact.

#ifndef PLAYER_GROUPED_TU
class RGE_World {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Player {
public:
    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int vf18(void);
    virtual int vf1C(void);
    virtual int isNeutral(int player_id);

    char gap_04[0x38];
    RGE_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x34];

    int isAllNeutral(void);
};
#endif

int RGE_Player::isAllNeutral(void) {
    RGE_Player* p = this;
    for (int i = 1; i < p->world->player_num; i++) {
        if (i != p->id) {
            if (p->isNeutral(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
