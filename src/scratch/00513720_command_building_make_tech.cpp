class RGE_Master_Static_Object_cbmt {
public:
    char gap_00[0x04];
    unsigned char master_type;
};

class RGE_Static_Object_cbmt {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object_cbmt* master;
};

class RGE_Command_cbmt {
public:
    void command_make_tech(RGE_Static_Object_cbmt* building, int tech_id);
};

class RGE_Game_World_cbmt {
public:
    char gap_00[0x58];
    RGE_Command_cbmt* command;
};

class TRIBE_Player_cbmt {
public:
    unsigned char command_building_make_tech(int tech_id);
    char gap_00[0x3C];
    RGE_Game_World_cbmt* world;
    char gap_40[0xF0];
    RGE_Static_Object_cbmt* selected_building;
};

unsigned char TRIBE_Player_cbmt::command_building_make_tech(int tech_id) {
    RGE_Static_Object_cbmt* b = this->selected_building;
    if (!b) return 0;
    if (b->master->master_type != 0x50) return 0;
    this->world->command->command_make_tech(b, tech_id);
    return 1;
}
