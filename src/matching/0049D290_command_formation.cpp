class RGE_Base_Game {
public:
    int get_paused(void);
    void* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

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
    virtual int vf20(void);
    virtual int vf24(void);
    virtual int vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int vf38(void);
    virtual int vf3C(void);
    virtual int vf40(void);
    virtual int vf44(void);
    virtual int vf48(void);
    virtual int vf4C(void);
    virtual int vf50(void);
    virtual int vf54(void);
    virtual int vf58(void);
    virtual int vf5C(void);
    virtual int vf60(void);
    virtual int vf64(void);
    virtual int vf68(void);
    virtual int vf6C(void);
    virtual int vf70(void);
    virtual int vf74(void);
    virtual int vf78(void);
    virtual int vf7C(void);
    virtual int vf80(void);
    virtual int vf84(void);
    virtual int vf88(void);
    virtual int vf8C(void);
    virtual int vf90(void);
    virtual int vf94(void);
    virtual int vf98(void);
    virtual int vf9C(void);
    virtual int vfA0(void);
    virtual int vfA4(void);
    virtual int vfA8(void);
    virtual int vfAC(void);
    virtual int vfB0(void);
    virtual int vfB4(void);
    virtual int vfB8(void);
    virtual void command_formation(int value);
};

class TRIBE_Screen_Game {
public:
    void command_formation(int value);
};

void TRIBE_Screen_Game::command_formation(int value) {
    if (rge_base_game->get_paused() == 0) {
        ((RGE_Player*)rge_base_game->get_player())->command_formation(value);
    }
}
