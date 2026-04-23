class RGE_Player;
class RGE_Command;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    char gap_00[0x4];
    unsigned char master_type;
    char gap_01[0xF];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_01[0xF0];
    RGE_Static_Object* selected_obj;
};

class RGE_Command {
public:
    void command_cancel_build(RGE_Static_Object* param_1);
};

class TRIBE_Player : public RGE_Player {
public:
    unsigned char command_building_cancel(void);
};

unsigned char TRIBE_Player::command_building_cancel(void) {
    RGE_Static_Object* selected_obj;

    selected_obj = this->selected_obj;
    if (selected_obj != 0) {
        if (selected_obj->owner == this) {
            if (selected_obj->master_obj->master_type == 'P' || selected_obj->master_obj->master_type == 'F') {
                if (selected_obj->master_obj->object_group != 1) {
                    this->world->commands->command_cancel_build(selected_obj);
                    return 1;
                }
            }
        }
    }

    return 0;
}
