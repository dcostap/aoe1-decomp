// VA: 00435020 RGE_Command::do_command_create_group
// Command.cpp lines 1018-1027.

#ifndef COMMAND_TU_CONTEXT
class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Command_Create_Group;
class RGE_Master_Static_Object;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;
class RGE_Object_Node;
class UnitAIModule;
template<class T> class ManagedArray { public: T* data; int count; int capacity; int grow_by; };

class RGE_Command {
public:
    virtual ~RGE_Command();
    RGE_Game_World* world;
    void do_command_create_group(RGE_Command_Create_Group* param_1);
};
class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Static_Object* object(int id);
};
class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_00[0x46];
    short id;
};
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    RGE_Object_Node* player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char pad_end;
    int commanderCreateGroup(int*, int, int, float);
};
class RGE_Command_Create_Group {
public:
    unsigned char command;
    unsigned char player_id;
    unsigned char pad_02[2];
    int groupCommander;
    float groupRange;
    int unitsToGroup[25];
    unsigned char numberUnitsToGroup;
};
#endif

void RGE_Command::do_command_create_group(RGE_Command_Create_Group* param_1) {
    RGE_Static_Object* object = this->world->object(param_1->groupCommander);
    if (object != 0 && object->owner->id == (unsigned short)param_1->player_id) {
        object->commanderCreateGroup(param_1->unitsToGroup,
                                     (int)param_1->numberUnitsToGroup,
                                     param_1->groupCommander,
                                     param_1->groupRange);
    }
}
