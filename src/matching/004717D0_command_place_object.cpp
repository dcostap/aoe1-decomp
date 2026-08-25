#ifndef PLAYER_GROUPED_TU
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Command {
public:
    void command_create(short object_id, short player_id, float x, float y, float z);
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;
};

class RGE_Player {
public:
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char _pad_0[0x1];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    char gap_40[0xA];
    short id;

    unsigned char command_place_object(short object_id, float x, float y, float z);
};
#endif

unsigned char RGE_Player::command_place_object(short object_id, float x, float y, float z) {
    if (object_id != -1 && this->master_objects[object_id] != 0) {
        this->world->command->command_create(object_id, this->id, x, y, z);
        return 1;
    }
    return 0;
}
