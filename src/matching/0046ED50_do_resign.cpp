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
    virtual void set_game_status(unsigned char);

    char gap_04[0x46];
    short id;
    short attribute_num_;
    char gap_4E[0x33];
    unsigned char resigned;

    void do_resign(int value);
};
#endif

void RGE_Player::do_resign(int value) {
    unsigned char resigned = this->resigned;
    this->resigned = 1;
    this->set_game_status(2);
    if (!resigned) {
        rge_base_game->vf40(5, this->id, value, 0, 0);
    }
}
