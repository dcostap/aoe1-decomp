class RGE_Master_Static_Object;

class TRIBE_Player {
public:
    char gap_00[0x54];
    unsigned char culture_id;
};

class TRIBE_Scenario_Editor_Panel_Object {
public:
    char gap_00[0x110];
    TRIBE_Player* player;
    char gap_114[0x100];
    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;

    void set_master_info(RGE_Master_Static_Object* master, TRIBE_Player* player);
};

void TRIBE_Scenario_Editor_Panel_Object::set_master_info(RGE_Master_Static_Object* master, TRIBE_Player* player) {
    this->master_game_obj = master;
    this->player = player;
    if (player == 0) {
        this->master_culture_id = 0;
        return;
    }
    this->master_culture_id = player->culture_id;
}
