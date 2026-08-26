// VA: 004C1590 | RGE_Static_Object::recycle_out_of_game | stat_obj.cpp:406-477
//
// Attempt log:
// baseline: natural typed cleanup reconstructed from the original call order,
// exact stat_obj.cpp layouts, and the executable's virtual slots.
// main-agent audit restored canonical object-list/master/player/world virtual
// ownership; emitted code remains exact.

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Victory_Conditions;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;
class RGE_Object_Node;
class UnitAIModule;

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Object_List {
public:
    virtual void load(unsigned char, int, RGE_Game_World*);
    RGE_Object_Node* list;
    short number_of_objects;

    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

class RGE_Tile {
public:
    char gap_00[0x0C];
    RGE_Object_List objects;
};

class RGE_Victory_Conditions {
public:
    void update_for_object(RGE_Static_Object* object);
};

class RGE_Active_Sprite_List {
public:
    void delete_list();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned char recycle_object_out_of_game(unsigned char type,
                                              RGE_Static_Object* object);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char gap_05[0x33];
    float radius_z;
    char gap_3C[0x68];
    unsigned char recyclable;
};

class RGE_Player {
public:
#define PLAYER_PAD(n) virtual void player_pad##n();
    virtual ~RGE_Player(); PLAYER_PAD(1)  PLAYER_PAD(2)  PLAYER_PAD(3)
    PLAYER_PAD(4)  PLAYER_PAD(5)  PLAYER_PAD(6)  PLAYER_PAD(7)
    PLAYER_PAD(8)  PLAYER_PAD(9)  PLAYER_PAD(10) PLAYER_PAD(11)
    PLAYER_PAD(12) PLAYER_PAD(13) PLAYER_PAD(14) PLAYER_PAD(15)
    PLAYER_PAD(16) PLAYER_PAD(17) PLAYER_PAD(18) PLAYER_PAD(19)
    PLAYER_PAD(20) PLAYER_PAD(21) PLAYER_PAD(22) PLAYER_PAD(23)
    PLAYER_PAD(24) PLAYER_PAD(25) PLAYER_PAD(26) PLAYER_PAD(27)
    PLAYER_PAD(28) PLAYER_PAD(29) PLAYER_PAD(30) PLAYER_PAD(31)
    PLAYER_PAD(32) PLAYER_PAD(33) PLAYER_PAD(34) PLAYER_PAD(35)
    PLAYER_PAD(36) PLAYER_PAD(37) PLAYER_PAD(38) PLAYER_PAD(39)
    PLAYER_PAD(40) PLAYER_PAD(41) PLAYER_PAD(42) PLAYER_PAD(43)
    PLAYER_PAD(44) PLAYER_PAD(45) PLAYER_PAD(46) PLAYER_PAD(47)
    PLAYER_PAD(48) PLAYER_PAD(49) PLAYER_PAD(50) PLAYER_PAD(51)
    PLAYER_PAD(52) PLAYER_PAD(53) PLAYER_PAD(54) PLAYER_PAD(55)
#undef PLAYER_PAD
    virtual void removeObject(RGE_Static_Object* object, int sleep,
                              int dopple, RGE_Object_Node* node);

    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0x04];
    RGE_Game_World* world;

    void unselect_one_object(RGE_Static_Object* object);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void recycle_out_of_game();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void enter_obj(RGE_Static_Object* object);
    virtual void exit_obj();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
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
    char gap_54[0x20];
    UnitAIModule* unitAIValue;

    void take_attribute_from_owner();
    int removeFromObstructionMap(int mode);
};
#endif

void RGE_Static_Object::recycle_out_of_game() {
    if (this->master_obj->recyclable != 0 &&
        this->owner->world->recycle_object_out_of_game(
            this->master_obj->master_type, this) != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            this->owner->victory_conditions->update_for_object(this);
        }
        if (this->sprite_list != 0) {
            this->sprite_list->delete_list();
        }
        if (this->owner != 0) {
            if ((this->selected & 1) != 0) {
                this->owner->unselect_one_object(this);
            }
            this->owner->removeObject(this, this->sleep_flag,
                                      this->dopple_flag,
                                      this->player_object_node);
            this->owner = 0;
        }
        if (this->tile != 0) {
            this->tile->objects.remove_node(this, 0);
            this->tile = 0;
        }
        if (this->inside_obj != 0) {
            this->inside_obj->objects->remove_node(this, 0);
            this->inside_obj = 0;
        }
        if (this->objects != 0) {
            RGE_Object_Node* node = this->objects->list;
            while (node != 0) {
                RGE_Object_Node* next = node->next;
                node->node->exit_obj();
                node = next;
            }
        }
        if (this->unitAIValue != 0) {
            delete this->unitAIValue;
            this->unitAIValue = 0;
        }
        if (this->master_obj != 0 && 0.0 < this->master_obj->radius_z) {
            this->removeFromObstructionMap(2);
        }
        this->master_obj = 0;
    } else {
        delete this;
    }
}
