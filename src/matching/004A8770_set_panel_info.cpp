#ifndef SCR_SED_TU_CONTEXT
class RGE_Player;
class RGE_Game_World;
class RGE_Base_Game;

class RGE_View {
public:
    void set_world(RGE_Game_World* world);
    void set_player(RGE_Player* player);
};

class RGE_Diamond_Map {
public:
    void set_world(RGE_Game_World* world);
    void set_player(RGE_Player* player);
};

class TRIBE_Main_View : public RGE_View {
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
};

extern RGE_Base_Game* rge_base_game;

class RGE_Base_Game {
public:
    RGE_Player* get_player(void);
};

class TRIBE_Screen_Sed {
public:
    char gap_00[0x4C8];
    TRIBE_Main_View* main_view;
    RGE_Diamond_Map_View* map_view;
    char gap_4D0[0x458];
    RGE_Game_World* world;

    void set_panel_info(void);
};
#endif

void TRIBE_Screen_Sed::set_panel_info(void) {
    this->main_view->set_world(this->world);
    this->main_view->set_player(rge_base_game->get_player());
    this->map_view->set_world(this->world);
    this->map_view->set_player(rge_base_game->get_player());
}
