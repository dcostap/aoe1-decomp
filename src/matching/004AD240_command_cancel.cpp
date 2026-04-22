class RGE_Base_Game {
public:
    void* get_player();
};

class RGE_Player {
public:
    void unselect_object();
    void unselect_area();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed {
public:
    void command_cancel();
};

void TRIBE_Screen_Sed::command_cancel() {
    ((RGE_Player*)rge_base_game->get_player())->unselect_object();
    ((RGE_Player*)rge_base_game->get_player())->unselect_area();
}
