class RGE_Base_Game {
public:
    char gap_00[0x3FC];
    short master_obj_id;
};

extern RGE_Base_Game* rge_base_game;

class RGE_Dialog_List {
public:
    char gap_00[0x4A8];
    int list_type;

    virtual short get_cur_id();
};

short RGE_Dialog_List::get_cur_id() {
    int list_type;
    RGE_Base_Game* base_game;

    list_type = this->list_type;
    if (--list_type != 0) {
        return -1;
    }
    base_game = rge_base_game;
    return base_game->master_obj_id;
}
