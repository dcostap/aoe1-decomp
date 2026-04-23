// tried world/player layout with the slot-0x20 virtual and the decompiler-style 1..player_num scan
// tried signed-short compare variants and a dummy local for the early player-count gate; mismatch stayed at the first compare/branch basin
// leaving in scratch: body shape is close, remaining gap is early branch distance / compare spelling

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

    char gap_00[0x38];
    RGE_World* world;
    char gap_40[0x0A];
    short id;

    int isAllNeutral(void);
};

int RGE_Player::isAllNeutral(void) {
    int iVar2 = 1;
    short one = 1;
    if (this->world->player_num <= one) {
        return 1;
    }
    do {
        if (iVar2 != (int)this->id) {
            if (this->relation_to_player(iVar2) == 0) {
                return 0;
            }
        }
        iVar2 = iVar2 + 1;
    } while (iVar2 < this->world->player_num);
    return 1;
}
