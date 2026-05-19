class RGE_Static_Object {
public:
    char gap0[0x38];
    float world_x;
    float world_y;
};

class RGE_Player {
public:
    void unselect_object();
    int select_object(RGE_Static_Object* obj);
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
};

class TRIBE_Player : public RGE_Player {
public:
    RGE_Static_Object* find_obj();
};

class RGE_Base_Game {
public:
    int get_paused();
    TRIBE_Player* get_player();
    TRIBE_Player* get_player(short player_id, int unused);
};

class RGE_ViewLike {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int value);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap0[0x4B8];
    RGE_ViewLike* main_view;

    void command_view_tribe();
};

void TRIBE_Screen_Game::command_view_tribe()
{
    if (rge_base_game->get_paused() == 0) {
        TRIBE_Player* player = rge_base_game->get_player(0x6d, 0);
        RGE_Static_Object* obj = player->find_obj();
        if (obj != 0) {
            rge_base_game->get_player()->unselect_object();
            rge_base_game->get_player()->select_object(obj);
            rge_base_game->get_player()->set_view_loc(obj->world_x, obj->world_y);
            rge_base_game->get_player()->set_map_loc((short)(int)obj->world_x, (short)(int)obj->world_y);
            main_view->vf20(1);
        }
    }
}
