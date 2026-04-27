// attempt 1: direct owner/world update with the virtual owner callback and the recyclable-object-id branch
// exact match landed once the first callback used player_object_node at +0x50 and the second callback stored the new node back there
#include "..\..\include\game_types.h"

class RGE_Object_Node;
class RGE_Tile_List;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;

class RGE_Tile_List { public: char pad[0x14]; };
class RGE_Game_World {
public:
    long get_next_object_id();
    long get_next_reusable_object_id();
};

class RGE_Player_vtable_pad {
public:
#define PAD_VIRTUAL(n) virtual void pad##n();
    PAD_VIRTUAL(0)
    PAD_VIRTUAL(1)
    PAD_VIRTUAL(2)
    PAD_VIRTUAL(3)
    PAD_VIRTUAL(4)
    PAD_VIRTUAL(5)
    PAD_VIRTUAL(6)
    PAD_VIRTUAL(7)
    PAD_VIRTUAL(8)
    PAD_VIRTUAL(9)
    PAD_VIRTUAL(10)
    PAD_VIRTUAL(11)
    PAD_VIRTUAL(12)
    PAD_VIRTUAL(13)
    PAD_VIRTUAL(14)
    PAD_VIRTUAL(15)
    PAD_VIRTUAL(16)
    PAD_VIRTUAL(17)
    PAD_VIRTUAL(18)
    PAD_VIRTUAL(19)
    PAD_VIRTUAL(20)
    PAD_VIRTUAL(21)
    PAD_VIRTUAL(22)
    PAD_VIRTUAL(23)
    PAD_VIRTUAL(24)
    PAD_VIRTUAL(25)
    PAD_VIRTUAL(26)
    PAD_VIRTUAL(27)
    PAD_VIRTUAL(28)
    PAD_VIRTUAL(29)
    PAD_VIRTUAL(30)
    PAD_VIRTUAL(31)
    PAD_VIRTUAL(32)
    PAD_VIRTUAL(33)
    PAD_VIRTUAL(34)
    PAD_VIRTUAL(35)
    PAD_VIRTUAL(36)
    PAD_VIRTUAL(37)
    PAD_VIRTUAL(38)
    PAD_VIRTUAL(39)
    PAD_VIRTUAL(40)
    PAD_VIRTUAL(41)
    PAD_VIRTUAL(42)
    PAD_VIRTUAL(43)
    PAD_VIRTUAL(44)
    PAD_VIRTUAL(45)
    PAD_VIRTUAL(46)
    PAD_VIRTUAL(47)
    PAD_VIRTUAL(48)
    PAD_VIRTUAL(49)
    PAD_VIRTUAL(50)
    PAD_VIRTUAL(51)
    PAD_VIRTUAL(52)
    PAD_VIRTUAL(53)
    PAD_VIRTUAL(54)
#undef PAD_VIRTUAL
};

class RGE_Player : public RGE_Player_vtable_pad {
public:
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3);
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4);

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
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char _pad_1[0x1];
    short id;
    short attribute_num;
    unsigned char _pad_2[0x2];
    float* attributes;
    unsigned char culture;
    unsigned char _pad_3[0x3];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    unsigned char game_status;
    unsigned char resigned;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0xA4];
    unsigned char recyclable;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x49 - 0x10];
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    char gap_4B[0x50 - 0x4B];
    RGE_Object_Node* player_object_node;

    void change_unique_id();
};

void RGE_Static_Object::change_unique_id() {
    this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);

    if (this->master_obj->recyclable != 0) {
        this->id = this->owner->world->get_next_reusable_object_id();
    } else {
        this->id = this->owner->world->get_next_object_id();
    }
    this->player_object_node = this->owner->addObject(this, this->sleep_flag, this->dopple_flag);
}
