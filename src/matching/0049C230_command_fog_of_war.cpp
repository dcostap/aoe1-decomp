#if !defined(SCR_GAME_TU_CONTEXT)
class TRIBE_World_FogState {
public:
    char gap_00[0x8DB9];
    unsigned char fog_of_war;
};

class TRIBE_World {
public:
    char gap_00[0x28];
    TRIBE_World_FogState* fog_state;
};

class TRIBE_Main_View {
public:
    virtual ~TRIBE_Main_View();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set_redraw(int mode);
};

class RGE_Base_Game {
public:
    char gap_00[0x982];
    unsigned char allowCheatCodes_;

    int allowCheatCodes();
    void set_map_fog(unsigned char param);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    TRIBE_Main_View* main_view;
    char gap_4BC[0xF8];
    TRIBE_World* world;

    void command_fog_of_war();
};
#endif

void TRIBE_Screen_Game::command_fog_of_war() {
    if (rge_base_game->allowCheatCodes()) {
        rge_base_game->set_map_fog(this->world->fog_state->fog_of_war == 0);
        this->main_view->set_redraw(2);
    }
}
