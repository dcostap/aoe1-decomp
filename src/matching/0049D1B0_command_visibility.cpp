#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    char gap_0[0x3F4];
    void* world;

    int allowCheatCodes();
    void set_map_visible(int param_1);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Map_View_Update {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void update(int param_1);
};

class TRIBE_World_Info {
public:
    char gap_0[0x8DB8];
    unsigned char cheat_visibility_flag;
};

class TRIBE_World {
public:
    char gap_0[0x28];
    TRIBE_World_Info* info;
};

class TRIBE_Screen_Game {
public:
    char gap_0[0x4B8];
    TRIBE_Map_View_Update* main_view;
    TRIBE_Map_View_Update* map_view;
    char gap_1[0xF4];
    TRIBE_World* world;

    void command_visibility();
};
#endif

void TRIBE_Screen_Game::command_visibility() {
    if (!rge_base_game->allowCheatCodes())
        return;

    rge_base_game->set_map_visible(this->world->info->cheat_visibility_flag == 0);
    this->main_view->update(2);
    this->map_view->update(2);
}
