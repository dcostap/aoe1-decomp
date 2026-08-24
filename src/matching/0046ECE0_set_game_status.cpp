// tried the direct status/resigned guard shape first
// tried the combined decompiler guard and explicit locals; mismatch stayed at the first-instruction/prolog basin
// remaining drift is the opening register load plus the base-game dispatch register order
// attempt 3: natural early-return style, inline rge_base_game, explicit local for this

#ifndef PLAYER_GROUPED_TU
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04(int);
    virtual void vf08(int);
    virtual void vf0C(int);
    virtual void vf10(int);
    virtual void vf14(int);
    virtual void vf18(int);
    virtual void vf1C(int);
    virtual void vf20(int);
    virtual void vf24(int);
    virtual void vf28(int);
    virtual void vf2C(int);
    virtual void vf30(int);
    virtual void vf34(int);
    virtual void vf38(int);
    virtual void vf3C(int);
    virtual void vf40(int, int, int, int, int);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04(int);
    virtual void set_game_status(unsigned char status);

    char gap_04[0x46];
    short id;
    char gap_4C[0x34];
    unsigned char game_status;
    unsigned char resigned;
    char gap_82[0x19E];

    void do_resign(int value);
};
#endif

void RGE_Player::set_game_status(unsigned char status) {
    RGE_Player* p = this;
    if (status == p->game_status) return;
    if (p->resigned && status != 2) return;
    p->game_status = status;
    if (status == 2 && !p->resigned) {
        rge_base_game->vf40(6, p->id, 0, 0, 0);
    }
}
