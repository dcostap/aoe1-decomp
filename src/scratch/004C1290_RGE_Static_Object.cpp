// 004C1290 RGE_Static_Object::~RGE_Static_Object
// PDB: stat_obj.cpp:192-327, 388 bytes
// __thiscall, void
// FLAGS: default + /GX (EH)
//
// Attempt log:
// - the initial flattened-array/root-dtor source matched the cleanup body but
//   lacked VC5's EH/member state and vtable context;
// - modeling the proven ManagedArray<int> members and using their natural
//   inline delete[] destructor restored the complete 388-byte EH-framed body;
// - correcting the owner addObject ABI to int sleep/dopple and the master
//   radius_z double comparison fixed the remaining call/FPU shape;
// - typed RGE_Player and inside-object ownership replaced raw offset casts
//   without changing bytes; exact 388-byte match, no asm or vptr store.

#include <stdlib.h>

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Master_Static_Object {
public:
    char gap_00[0x38];
    float radius_z;
};
extern "C" void __cdecl operator_delete(void* ptr);

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    ~ManagedArrayInt() {
        if (this->value != 0) {
            delete[] this->value;
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }
};

struct RGE_Object_Node {
    void* object;               // +0x00
    RGE_Object_Node* next;      // +0x04
};

struct RGE_Object_List {
    virtual ~RGE_Object_List();
    RGE_Object_Node* head;      // +0x04
    void remove_node(void* obj, RGE_Object_Node* node);
};

struct RGE_Tile {
    char gap_00[0x0C];
    RGE_Object_List objects;    // +0x0C (embedded)
};

struct RGE_Victory_Conditions {
    void update_for_object(void* obj);
};

struct RGE_Player {
    virtual ~RGE_Player();
#define PLAYER_SLOT(n) virtual void slot_##n();
    PLAYER_SLOT(04) PLAYER_SLOT(08) PLAYER_SLOT(0C) PLAYER_SLOT(10)
    PLAYER_SLOT(14) PLAYER_SLOT(18) PLAYER_SLOT(1C) PLAYER_SLOT(20)
    PLAYER_SLOT(24) PLAYER_SLOT(28) PLAYER_SLOT(2C) PLAYER_SLOT(30)
    PLAYER_SLOT(34) PLAYER_SLOT(38) PLAYER_SLOT(3C) PLAYER_SLOT(40)
    PLAYER_SLOT(44) PLAYER_SLOT(48) PLAYER_SLOT(4C) PLAYER_SLOT(50)
    PLAYER_SLOT(54) PLAYER_SLOT(58) PLAYER_SLOT(5C) PLAYER_SLOT(60)
    PLAYER_SLOT(64) PLAYER_SLOT(68) PLAYER_SLOT(6C) PLAYER_SLOT(70)
    PLAYER_SLOT(74) PLAYER_SLOT(78) PLAYER_SLOT(7C) PLAYER_SLOT(80)
    PLAYER_SLOT(84) PLAYER_SLOT(88) PLAYER_SLOT(8C) PLAYER_SLOT(90)
    PLAYER_SLOT(94) PLAYER_SLOT(98) PLAYER_SLOT(9C) PLAYER_SLOT(A0)
    PLAYER_SLOT(A4) PLAYER_SLOT(A8) PLAYER_SLOT(AC) PLAYER_SLOT(B0)
    PLAYER_SLOT(B4) PLAYER_SLOT(B8) PLAYER_SLOT(BC) PLAYER_SLOT(C0)
    PLAYER_SLOT(C4) PLAYER_SLOT(C8) PLAYER_SLOT(CC) PLAYER_SLOT(D0)
    PLAYER_SLOT(D4) PLAYER_SLOT(D8) PLAYER_SLOT(DC)
#undef PLAYER_SLOT
    virtual void removeObject(void* obj, int sleep, int dopple, void* node);
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;  // +0x34
    char gap_38[0x11];
    unsigned char sleep_flag;   // +0x49
    unsigned char dopple_flag;  // +0x4A
    char gap_4B[0x01];
    void unselect_one_object(void* obj);
};

struct UnitAIModule {
    virtual ~UnitAIModule();
};

struct RGE_Static_Object {
    // compiler-managed vtable at +0x00
    long id;                                       // +0x04
    RGE_Master_Static_Object* master_obj;          // +0x08
    RGE_Player* owner;                              // +0x0C
    void* sprite;                                  // +0x10
    void* old_sprite;                              // +0x14
    RGE_Object_List* sprite_list;                  // +0x18
    RGE_Tile* tile;                                // +0x1C
    RGE_Static_Object* inside_obj;                 // +0x20
    RGE_Object_List* objects;                      // +0x24
    short screen_x_offset;                         // +0x28
    short screen_y_offset;                         // +0x2A
    short shadow_x_offset;                         // +0x2C
    short shadow_y_offset;                         // +0x2E
    float hp;                                      // +0x30
    unsigned char curr_damage_percent;              // +0x34
    unsigned char facet;                           // +0x35
    unsigned char selected;                        // +0x36
    unsigned char selected_group;                  // +0x37
    float world_x;                                 // +0x38
    float world_y;                                 // +0x3C
    float world_z;                                 // +0x40
    float attribute_amount_held;                   // +0x44
    unsigned char object_state;                    // +0x48
    unsigned char sleep_flag;                      // +0x49
    unsigned char dopple_flag;                     // +0x4A
    unsigned char goto_sleep_flag;                 // +0x4B
    short attribute_type_held;                     // +0x4C
    unsigned char type;                            // +0x4E
    unsigned char worker_num;                      // +0x4F
    void* player_object_node;                      // +0x50

    ManagedArrayInt pathingGroupMembers;           // +0x54
    ManagedArrayInt groupMembers;                  // +0x64

    void* unitAIValue;                             // +0x74
    int groupCommanderValue;                       // +0x78
    int zoneMapIndex;                              // +0x7C
    float groupRangeValue;                         // +0x80
    unsigned char inObstructionMapValue;            // +0x84
    unsigned char lastInObstructionMapValue;        // +0x85
    unsigned char underAttackValue;                 // +0x86

    virtual ~RGE_Static_Object();
#define OBJECT_SLOT(n) virtual void slot_##n();
    OBJECT_SLOT(04) OBJECT_SLOT(08) OBJECT_SLOT(0C) OBJECT_SLOT(10)
    OBJECT_SLOT(14) OBJECT_SLOT(18) OBJECT_SLOT(1C) OBJECT_SLOT(20)
    OBJECT_SLOT(24) OBJECT_SLOT(28) OBJECT_SLOT(2C) OBJECT_SLOT(30)
    OBJECT_SLOT(34) OBJECT_SLOT(38) OBJECT_SLOT(3C) OBJECT_SLOT(40)
    OBJECT_SLOT(44) OBJECT_SLOT(48) OBJECT_SLOT(4C) OBJECT_SLOT(50)
    OBJECT_SLOT(54) OBJECT_SLOT(58) OBJECT_SLOT(5C) OBJECT_SLOT(60)
    OBJECT_SLOT(64) OBJECT_SLOT(68) OBJECT_SLOT(6C) OBJECT_SLOT(70)
    OBJECT_SLOT(74) OBJECT_SLOT(78) OBJECT_SLOT(7C) OBJECT_SLOT(80)
    OBJECT_SLOT(84) OBJECT_SLOT(88) OBJECT_SLOT(8C) OBJECT_SLOT(90)
    OBJECT_SLOT(94) OBJECT_SLOT(98) OBJECT_SLOT(9C) OBJECT_SLOT(A0)
    OBJECT_SLOT(A4) OBJECT_SLOT(A8) OBJECT_SLOT(AC) OBJECT_SLOT(B0)
    OBJECT_SLOT(B4) OBJECT_SLOT(B8) OBJECT_SLOT(BC) OBJECT_SLOT(C0)
    OBJECT_SLOT(C4) OBJECT_SLOT(C8) OBJECT_SLOT(CC) OBJECT_SLOT(D0)
#undef OBJECT_SLOT
    virtual void release_from_holder();

    void remove_visible_resource();
    void take_attribute_from_owner();
    int removeFromObstructionMap(int param);
};
#endif

RGE_Static_Object::~RGE_Static_Object() {
    this->remove_visible_resource();

    if (this->owner != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            this->owner->victory_conditions->update_for_object(this);
        }
    }

    if (this->sprite_list != 0) {
        delete this->sprite_list;
        this->sprite_list = 0;
    }

    if (this->owner != 0) {
        if (this->selected & 1) {
            this->owner->unselect_one_object(this);
        }

        this->owner->removeObject(this, this->sleep_flag, this->dopple_flag,
                                  this->player_object_node);

        this->owner = 0;
    }

    if (this->tile != 0) {
        this->tile->objects.remove_node(this, 0);
        this->tile = 0;
    }

    if (this->master_obj != 0) {
        if (this->master_obj->radius_z > 0.0) {
            this->removeFromObstructionMap(2);
        }
    }

    if (this->inside_obj != 0) {
        this->inside_obj->objects->remove_node(this, 0);
        this->inside_obj = 0;
    }

    if (this->objects != 0) {
        RGE_Object_Node* node = this->objects->head;
        while (node != 0) {
            RGE_Object_Node* next = node->next;
            ((RGE_Static_Object*)node->object)->release_from_holder();
            node = next;
        }

        RGE_Object_List* list = this->objects;
        if (list != 0) {
            list->RGE_Object_List::~RGE_Object_List();
            operator_delete(list);
        }
    }

    if (this->unitAIValue != 0) {
        delete (UnitAIModule*)this->unitAIValue;
        this->unitAIValue = 0;
    }

}
