class RGE_Master_Static_Object_cbmo {
public:
    char gap_00[0x04];
    unsigned char master_type;
};

class RGE_Static_Object_cbmo {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object_cbmo* master;
};

class RGE_Command_cbmo {
public:
    void command_make_obj(RGE_Static_Object_cbmo* building, int obj_id);
};

class RGE_Game_World_cbmo {
public:
    char gap_00[0x58];
    RGE_Command_cbmo* command;
};

class TRIBE_Player_cbmo {
public:
    unsigned char command_building_make_obj(int obj_id);
    char gap_00[0x3C];
    RGE_Game_World_cbmo* world;
    char gap_40[0xF0];
    RGE_Static_Object_cbmo* selected_building;
};

unsigned char TRIBE_Player_cbmo::command_building_make_obj(int obj_id) {
    RGE_Static_Object_cbmo* b = this->selected_building;
    if (!b) return 0;
    if (b->master->master_type != 0x50) return 0;
    this->world->command->command_make_obj(b, obj_id);
    return 1;
}
