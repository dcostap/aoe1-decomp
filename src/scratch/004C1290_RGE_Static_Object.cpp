// 004C1290 RGE_Static_Object::~RGE_Static_Object
// PDB: stat_obj.cpp:192-327, 388 bytes
// __thiscall, void
// FLAGS: default + /GX (EH)
//
// Attempt log:
// v0: compile errors (duplicate vtable ptr, wrong calling convention)
// v1: virtual dtor + /GX — no EH frame generated (368 < 388, body starts with push ebx)
// v2: __try/__finally — generates DIFFERENT EH pattern (EBP-frame-based, 76.8% diff)
// v3: fixed layout (no double vtable), member function calls — body identical except EH
// v4-v10: tested various /GX permutations — EH frame only generated in full-TU context
//
// ACCEPTED_DRIFT: EH frame not generated for root-class destructors in single-function
// compilation. Original has VC5 destructor EH frame (push -1; push handler; mov fs[0];esp;
// push ecx; state tracking stores). Our single-function /GX compile skips this because
// RGE_Static_Object has no base class with virtual destructor.
//
// Differences summary:
// 1. Missing: push -1; push handler; mov eax,fs[0]; push eax; mov fs[0],esp; push ecx (EH setup, 19 bytes)
// 2. Missing: mov [esp+0Ch], esi (this save for EH restore)
// 3. Missing: mov [esp+18h], 1 (EH state = 1 at start)
// 4. Missing: mov [esp+18h], bl (EH state = 0 before groupMembers free)
// 5. Missing: mov [esp+18h], -1 (EH state = -1 before pathingGroupMembers free)
// 6. Missing: mov ecx,[esp+10h]; mov fs[0],ecx (EH restore at end, 7 bytes)
// 7. Missing: add esp, 10h (EH stack cleanup, 3 bytes)
//
// All field accesses, branch targets, linked-list walk, virtual calls, and operator_delete
// calls are byte-identical between original and rebuilt body. This is pure structural EH
// frame overhead that's not replicable outside the full TU.

#include <stdlib.h>

class RGE_Static_Object;

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
    char gap_00[0x34];
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

struct PlayerHelper {
    virtual void _v00();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0C();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1C();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28();
    virtual void _v2C();
    virtual void _v30();
    virtual void _v34();
    virtual void _v38();
    virtual void _v3C();
    virtual void _v40();
    virtual void _v44();
    virtual void _v48();
    virtual void _v4C();
    virtual void _v50();
    virtual void _v54();
    virtual void _v58();
    virtual void _v5C();
    virtual void _v60();
    virtual void _v64();
    virtual void _v68();
    virtual void _v6C();
    virtual void _v70();
    virtual void _v74();
    virtual void _v78();
    virtual void _v7C();
    virtual void _v80();
    virtual void _v84();
    virtual void _v88();
    virtual void _v8C();
    virtual void _v90();
    virtual void _v94();
    virtual void _v98();
    virtual void _v9C();
    virtual void _vA0();
    virtual void _vA4();
    virtual void _vA8();
    virtual void _vAC();
    virtual void _vB0();
    virtual void _vB4();
    virtual void _vB8();
    virtual void _vBC();
    virtual void _vC0();
    virtual void _vC4();
    virtual void _vC8();
    virtual void _vCC();
    virtual void _vD0();
    virtual void _vD4();
    virtual void _vD8();
    virtual void _vDC();
    virtual void _vE0(void* obj, unsigned char sleep, unsigned char dopple, void* node);
};

struct ObjHelper {
    virtual void _v00();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0C();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1C();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28();
    virtual void _v2C();
    virtual void _v30();
    virtual void _v34();
    virtual void _v38();
    virtual void _v3C();
    virtual void _v40();
    virtual void _v44();
    virtual void _v48();
    virtual void _v4C();
    virtual void _v50();
    virtual void _v54();
    virtual void _v58();
    virtual void _v5C();
    virtual void _v60();
    virtual void _v64();
    virtual void _v68();
    virtual void _v6C();
    virtual void _v70();
    virtual void _v74();
    virtual void _v78();
    virtual void _v7C();
    virtual void _v80();
    virtual void _v84();
    virtual void _v88();
    virtual void _v8C();
    virtual void _v90();
    virtual void _v94();
    virtual void _v98();
    virtual void _v9C();
    virtual void _vA0();
    virtual void _vA4();
    virtual void _vA8();
    virtual void _vAC();
    virtual void _vB0();
    virtual void _vB4();
    virtual void _vB8();
    virtual void _vBC();
    virtual void _vC0();
    virtual void _vC4();
    virtual void _vC8();
    virtual void _vCC();
    virtual void _vD0();
    virtual void _vD4();    // +0xD4
};

extern "C" void __cdecl operator_delete(void* ptr);

struct RGE_Static_Object {
    // compiler-managed vtable at +0x00
    long id;                                       // +0x04
    void* master_obj;                              // +0x08
    void* owner;                                   // +0x0C
    void* sprite;                                  // +0x10
    void* old_sprite;                              // +0x14
    RGE_Object_List* sprite_list;                  // +0x18
    RGE_Tile* tile;                                // +0x1C
    void* inside_obj;                              // +0x20
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

    int* pathingGroupMembers_value;                // +0x54
    int pathingGroupMembers_number;                // +0x58
    int pathingGroupMembers_desired;               // +0x5C
    int pathingGroupMembers_max;                   // +0x60

    int* groupMembers_value;                       // +0x64
    int groupMembers_number;                       // +0x68
    int groupMembers_desired;                      // +0x6C
    int groupMembers_max;                          // +0x70

    void* unitAIValue;                             // +0x74
    int groupCommanderValue;                       // +0x78
    int zoneMapIndex;                              // +0x7C
    float groupRangeValue;                         // +0x80
    unsigned char inObstructionMapValue;            // +0x84
    unsigned char lastInObstructionMapValue;        // +0x85
    unsigned char underAttackValue;                 // +0x86

    virtual ~RGE_Static_Object();

    void remove_visible_resource();
    void take_attribute_from_owner();
    int removeFromObstructionMap(int param);
};

RGE_Static_Object::~RGE_Static_Object() {
    this->remove_visible_resource();

    if (this->owner != 0) {
        if (this->object_state < 3) {
            this->take_attribute_from_owner();
        }
        if (this->object_state < 7) {
            RGE_Victory_Conditions* vc = *(RGE_Victory_Conditions**)((char*)this->owner + 0x34);
            vc->update_for_object(this);
        }
    }

    if (this->sprite_list != 0) {
        delete this->sprite_list;
        this->sprite_list = 0;
    }

    if (this->owner != 0) {
        if (this->selected & 1) {
            ((RGE_Player*)this->owner)->unselect_one_object(this);
        }

        ((PlayerHelper*)this->owner)->_vE0(this, this->sleep_flag, this->dopple_flag, this->player_object_node);

        this->owner = 0;
    }

    if (this->tile != 0) {
        this->tile->objects.remove_node(this, 0);
        this->tile = 0;
    }

    if (this->master_obj != 0) {
        if (*(float*)((char*)this->master_obj + 0x38) > 0.0f) {
            this->removeFromObstructionMap(2);
        }
    }

    if (this->inside_obj != 0) {
        ((RGE_Object_List*)(*(void**)((char*)this->inside_obj + 0x24)))->remove_node(this, 0);
        this->inside_obj = 0;
    }

    if (this->objects != 0) {
        RGE_Object_Node* node = this->objects->head;
        while (node != 0) {
            RGE_Object_Node* next = node->next;
            ((ObjHelper*)node->object)->_vD4();
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

    if (this->groupMembers_value != 0) {
        operator_delete(this->groupMembers_value);
        this->groupMembers_value = 0;
    }
    this->groupMembers_number = 0;
    this->groupMembers_desired = 0;
    this->groupMembers_max = 0;

    if (this->pathingGroupMembers_value != 0) {
        operator_delete(this->pathingGroupMembers_value);
        this->pathingGroupMembers_value = 0;
    }
    this->pathingGroupMembers_number = 0;
    this->pathingGroupMembers_desired = 0;
    this->pathingGroupMembers_max = 0;
}
