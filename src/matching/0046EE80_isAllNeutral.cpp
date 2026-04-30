// tried world/player layout with the slot-0x20 virtual and the decompiler-style 1..player_num scan
// tried signed-short compare variants and a dummy local for the early player-count gate; mismatch stayed at the first compare/branch basin
// leaving in scratch: body shape is close, remaining gap is early branch distance / compare spelling
// attempt 2: natural for-loop with esi-stored this

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
    virtual int relation_to_player(int player_id);

    char gap_04[0x38];
    RGE_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x34];

    int isAllNeutral(void);
};

int RGE_Player::isAllNeutral(void) {
    RGE_Player* p = this;
    for (int i = 1; i < p->world->player_num; i++) {
        if (i != p->id) {
            if (p->relation_to_player(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
