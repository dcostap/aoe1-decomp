class GlobalPlayerHost {
public:
    virtual void vf00(void);
    virtual void vf01(void);
    virtual void vf02(void);
    virtual void vf03(void);
    virtual void vf04(void);
    virtual void vf05(int arg);
};

extern GlobalPlayerHost* g_game;

class CommandPlayerHost {
public:
    void command_player(int param);
};

void CommandPlayerHost::command_player(int param) {
    g_game->vf05(param);
}
