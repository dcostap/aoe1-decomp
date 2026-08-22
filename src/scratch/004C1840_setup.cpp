// 004C1840 RGE_Static_Object::setup(int, RGE_Game_World*)
// Attempt log:
// - Baseline used local raw array fields and incorrect renderer/object helper
//   surfaces; it had the right save-read prefix but wrong frame and final calls.
// - Reconstructing the canonical RGE_Static_Object/ManagedArray layout and
//   stat_obj.cpp save-load source is the current structural pass.
// - Canonical sprite-list load, world callback, object-list add, and vtable
//   slots aligned all 45 calls; period float literals restored the original
//   one-operand fcomp form and the bounded indexed loops improved CFG/size.
// - Remaining drift is the VC5 prologue/register/local-home basin and a few
//   loop block spans; direct parameter-home handle reuse was tested and made
//   the function 131 bytes larger, so it was rolled back.
// - Natural first-read handle split (incoming file for the first read, then a
//   local handle for later reads) moved the result farther to 1161 bytes, so
//   it was rolled back.
// - Corrected the proven world players offset to +0x40 and modeled the two
//   serialized member counts as int; the latter removed 12 bytes of mask code
//   and improved the strict diff to 883 bytes.
// - A do-while scan rewrite expanded the CFG and lost exact loop islands; it
//   was rolled back to the bounded for-loop form.
// - Donor-backed count-first scans and the inverted direct add_node tail
//   restore the original CFG islands, but register colors and local homes
//   still differ from the executable.
// - The original writes short indices into the incoming file/world homes;
//   keep the saved handle separate and preserve those parameter-home writes.
// - The reviewed DAT_00574724 and DAT_00574728 symbols recover the two rdata
//   comparison operands.  No source or context probe fixed the prologue basin.
// - Twenty-one hypotheses covered handle aliases, parameter-home reuse,
//   scalar scopes and order, array layout, loop forms, branch polarity, direct
//   calls, rdata symbols, and a local aggregate.  The current source is the
//   clearest donor-backed form.  Next lead: recover the original TU local
//   declaration context or register basin before further body rewrites.
// - Earlier direct-call tail work was superseded.  The current inverted branch
//   form restores the original tail block islands with the donor-backed scans.
// - A six-word local aggregate in binary stack order recovered the original
//   homes, but main review rejected it as local-home steering. A natural short
//   serialization index remains because it models the two-byte reads.
// - Tested register qualifiers, declaration order, aliases, narrow byte type,
//   header context, named zero, and nested scans; none changed the best basin.
// - Final unresolved residue is the callee-saved register permutation: the
//   build uses EBP for the file and EBX for zero, while the executable uses
//   EDI for file, EBX for world, and EBP for zero.

#include "../../include/game_globals.h"

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Object_List;
class RGE_Object_Node;

extern void rge_read(int file, void* buffer, int size);
extern void* operator new(unsigned int size);
extern void operator delete(void* ptr);

extern float save_game_version;

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    int gap_0C;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
    short number_of_objects;
    RGE_Object_Node* add_node(RGE_Static_Object* object);
};

class RGE_Active_Sprite_List {
public:
    void load(int file, RGE_Sprite** sprites);
};

class RGE_Game_World {
public:
#define WORLD_PAD(n) virtual void world_pad##n();
    WORLD_PAD(00) WORLD_PAD(01) WORLD_PAD(02) WORLD_PAD(03)
    WORLD_PAD(04) WORLD_PAD(05) WORLD_PAD(06) WORLD_PAD(07)
    WORLD_PAD(08) WORLD_PAD(09) WORLD_PAD(10) WORLD_PAD(11)
    WORLD_PAD(12) WORLD_PAD(13) WORLD_PAD(14) WORLD_PAD(15)
    WORLD_PAD(16) WORLD_PAD(17) WORLD_PAD(18) WORLD_PAD(19)
    WORLD_PAD(20) WORLD_PAD(21) WORLD_PAD(22) WORLD_PAD(23)
    WORLD_PAD(24) WORLD_PAD(25) WORLD_PAD(26) WORLD_PAD(27)
    WORLD_PAD(28) WORLD_PAD(29) WORLD_PAD(30) WORLD_PAD(31)
    WORLD_PAD(32) WORLD_PAD(33) WORLD_PAD(34) WORLD_PAD(35)
    WORLD_PAD(36) WORLD_PAD(37) WORLD_PAD(38) WORLD_PAD(39)
    WORLD_PAD(40) WORLD_PAD(41) WORLD_PAD(42) WORLD_PAD(43)
    WORLD_PAD(44) WORLD_PAD(45) WORLD_PAD(46) WORLD_PAD(47)
    WORLD_PAD(48) WORLD_PAD(49) WORLD_PAD(50) WORLD_PAD(51)
    WORLD_PAD(52) WORLD_PAD(53) WORLD_PAD(54) WORLD_PAD(55)
    WORLD_PAD(56) WORLD_PAD(57) WORLD_PAD(58) WORLD_PAD(59)
    WORLD_PAD(60) WORLD_PAD(61)
    virtual void add_object(RGE_Static_Object* object);
#undef WORLD_PAD
    char gap_04[0x34];
    RGE_Sprite** sprites;                    // +0x38
    char gap_3C[4];
    RGE_Player** players;                    // +0x40
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects; // +0x24
    RGE_Object_List* objects;                 // +0x28
    RGE_Object_List* sleeping_objects;        // +0x2C
    RGE_Object_List* doppleganger_objects;    // +0x30
    char gap_34[8];
    RGE_Game_World* world;                    // +0x3C
};

class RGE_Static_Object_vtable_pad {
public:
#define OBJECT_PAD(n) virtual void object_pad##n();
    OBJECT_PAD(00) OBJECT_PAD(04) OBJECT_PAD(08) OBJECT_PAD(0C)
    OBJECT_PAD(10) OBJECT_PAD(14) OBJECT_PAD(18) OBJECT_PAD(1C)
    OBJECT_PAD(20) OBJECT_PAD(24) OBJECT_PAD(28) OBJECT_PAD(2C)
    OBJECT_PAD(30)
#undef OBJECT_PAD
};

class RGE_Static_Object : public RGE_Static_Object_vtable_pad {
public:
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite* sprite);
#define OBJECT_PAD2(n) virtual void object_pad2_##n();
    OBJECT_PAD2(000) OBJECT_PAD2(001) OBJECT_PAD2(002) OBJECT_PAD2(003)
    OBJECT_PAD2(004) OBJECT_PAD2(005) OBJECT_PAD2(006) OBJECT_PAD2(007)
    OBJECT_PAD2(008) OBJECT_PAD2(009) OBJECT_PAD2(010) OBJECT_PAD2(011)
    OBJECT_PAD2(012) OBJECT_PAD2(013) OBJECT_PAD2(014) OBJECT_PAD2(015)
    OBJECT_PAD2(016) OBJECT_PAD2(017) OBJECT_PAD2(018) OBJECT_PAD2(019)
    OBJECT_PAD2(020) OBJECT_PAD2(021) OBJECT_PAD2(022) OBJECT_PAD2(023)
    OBJECT_PAD2(024) OBJECT_PAD2(025) OBJECT_PAD2(026) OBJECT_PAD2(027)
    OBJECT_PAD2(028) OBJECT_PAD2(029) OBJECT_PAD2(030) OBJECT_PAD2(031)
    OBJECT_PAD2(032) OBJECT_PAD2(033) OBJECT_PAD2(034) OBJECT_PAD2(035)
    OBJECT_PAD2(036) OBJECT_PAD2(037) OBJECT_PAD2(038) OBJECT_PAD2(039)
    OBJECT_PAD2(040) OBJECT_PAD2(041) OBJECT_PAD2(042) OBJECT_PAD2(043)
    OBJECT_PAD2(044) OBJECT_PAD2(045) OBJECT_PAD2(046) OBJECT_PAD2(047)
    OBJECT_PAD2(048) OBJECT_PAD2(049) OBJECT_PAD2(050) OBJECT_PAD2(051)
    OBJECT_PAD2(052) OBJECT_PAD2(053) OBJECT_PAD2(054) OBJECT_PAD2(055)
    OBJECT_PAD2(056) OBJECT_PAD2(057) OBJECT_PAD2(058) OBJECT_PAD2(059)
    OBJECT_PAD2(060) OBJECT_PAD2(061) OBJECT_PAD2(062) OBJECT_PAD2(063)
    OBJECT_PAD2(064) OBJECT_PAD2(065) OBJECT_PAD2(066) OBJECT_PAD2(067)
    OBJECT_PAD2(068) OBJECT_PAD2(069) OBJECT_PAD2(070) OBJECT_PAD2(071)
    OBJECT_PAD2(072) OBJECT_PAD2(073) OBJECT_PAD2(074) OBJECT_PAD2(075)
    OBJECT_PAD2(076) OBJECT_PAD2(077) OBJECT_PAD2(078) OBJECT_PAD2(079)
    OBJECT_PAD2(080) OBJECT_PAD2(081) OBJECT_PAD2(082) OBJECT_PAD2(083)
    OBJECT_PAD2(084) OBJECT_PAD2(085) OBJECT_PAD2(086) OBJECT_PAD2(087)
    OBJECT_PAD2(088) OBJECT_PAD2(089) OBJECT_PAD2(090) OBJECT_PAD2(091)
    OBJECT_PAD2(092) OBJECT_PAD2(093) OBJECT_PAD2(094) OBJECT_PAD2(095)
    OBJECT_PAD2(096) OBJECT_PAD2(097) OBJECT_PAD2(098) OBJECT_PAD2(099)
    OBJECT_PAD2(100) OBJECT_PAD2(101) OBJECT_PAD2(102) OBJECT_PAD2(103)
    OBJECT_PAD2(104)
#undef OBJECT_PAD2
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

    long id;                                      // +0x04
    RGE_Master_Static_Object* master_obj;        // +0x08
    RGE_Player* owner;                            // +0x0C
    RGE_Sprite* sprite;                           // +0x10
    RGE_Sprite* old_sprite;                       // +0x14
    RGE_Active_Sprite_List* sprite_list;          // +0x18
    void* tile;                                   // +0x1C
    RGE_Static_Object* inside_obj;                // +0x20
    RGE_Object_List* objects;                     // +0x24
    short screen_x_offset;                        // +0x28
    short screen_y_offset;                        // +0x2A
    short shadow_x_offset;                       // +0x2C
    short shadow_y_offset;                        // +0x2E
    float hp;                                     // +0x30
    unsigned char curr_damage_percent;            // +0x34
    unsigned char facet;                          // +0x35
    unsigned char selected;                       // +0x36
    unsigned char selected_group;                 // +0x37
    float world_x;                                // +0x38
    float world_y;                                // +0x3C
    float world_z;                                // +0x40
    float attribute_amount_held;                  // +0x44
    unsigned char object_state;                   // +0x48
    unsigned char sleep_flag;                     // +0x49
    unsigned char dopple_flag;                    // +0x4A
    unsigned char goto_sleep_flag;                // +0x4B
    short attribute_type_held;                    // +0x4C
    unsigned char type;                            // +0x4E
    unsigned char worker_num;                     // +0x4F
    RGE_Object_Node* player_object_node;          // +0x50
    ManagedArrayInt pathingGroupMembers;          // +0x54
    ManagedArrayInt groupMembers;                 // +0x64
    void* unitAIValue;                             // +0x74
    int groupCommanderValue;                      // +0x78
    int zoneMapIndex;                              // +0x7C
    float groupRangeValue;                         // +0x80
    unsigned char inObstructionMapValue;           // +0x84
    unsigned char lastInObstructionMapValue;        // +0x85
    unsigned char underAttackValue;                // +0x86

    int setup(int file, RGE_Game_World* world);

};

int RGE_Static_Object::setup(int file, RGE_Game_World* world) {
    int save_file = file;
    int long_val;
    int byte_val;
    int numberUnits;
    int tempInt;
    int tempInt_fffffff8;
    int local_4;
    short index;

    this->type = 10;
    rge_read(save_file, &long_val, 1);
    this->owner = world->players[long_val & 0xff];

    // BINARY NOTE: The shipped loader reuses the incoming file home for this index.
    rge_read(save_file, &index, 2);
    this->master_obj = this->owner->master_objects[index];

    rge_read(save_file, &index, 2);
    if (index >= 0) {
        this->sprite = world->sprites[index];
    } else {
        this->sprite = 0;
    }

    this->old_sprite = 0;
    rge_read(save_file, &tempInt, 4);
    if (tempInt == -1) {
        this->inside_obj = 0;
    } else {
        this->inside_obj = (RGE_Static_Object*)tempInt;
    }

    rge_read(save_file, &this->hp, 4);
    rge_read(save_file, &this->object_state, 1);
    rge_read(save_file, &this->sleep_flag, 1);
    if (save_game_version >= DAT_00574724) {
        rge_read(save_file, &this->dopple_flag, 1);
    }
    rge_read(save_file, &this->goto_sleep_flag, 1);
    rge_read(save_file, &this->id, 4);
    rge_read(save_file, &this->facet, 1);
    rge_read(save_file, &this->world_x, 4);
    rge_read(save_file, &this->world_y, 4);
    rge_read(save_file, &this->world_z, 4);
    rge_read(save_file, &this->screen_x_offset, 2);
    rge_read(save_file, &this->screen_y_offset, 2);
    rge_read(save_file, &this->shadow_x_offset, 2);
    rge_read(save_file, &this->shadow_y_offset, 2);
    rge_read(save_file, &this->selected_group, 1);
    rge_read(save_file, &this->attribute_type_held, 2);
    rge_read(save_file, &this->attribute_amount_held, 4);
    rge_read(save_file, &this->worker_num, 1);
    rge_read(save_file, &this->curr_damage_percent, 1);
    rge_read(save_file, &this->underAttackValue, 1);
    this->tile = 0;
    rge_read(save_file, &this->groupCommanderValue, 4);
    rge_read(save_file, &this->groupRangeValue, 4);

    if (save_game_version == DAT_00574728) {
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &numberUnits, 4);
        rge_read(save_file, &local_4, 4);
        rge_read(save_file, &tempInt_fffffff8, 4);
        rge_read(save_file, &tempInt_fffffff8, 4);
    }

    rge_read(save_file, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            rge_read(save_file, &tempInt_fffffff8, 4);
            // BINARY NOTE: The duplicate scan checks count before capacity.
            int number = this->groupMembers.numberValue;
            int index = 0;
            local_4 = tempInt_fffffff8;
            for (; index < number && index < this->groupMembers.maximumSizeValue;
                 index = index + 1) {
                if (this->groupMembers.value[index] == tempInt_fffffff8) {
                    goto group_member_found;
                }
            }
            if (number > this->groupMembers.maximumSizeValue - 1) {
                int newNumber = number + 1;
                int* values = (int*)operator new(newNumber * 4);
                if (values != 0) {
                    index = 0;
                    for (; index < this->groupMembers.maximumSizeValue && index < newNumber;
                         index = index + 1) {
                        values[index] = this->groupMembers.value[index];
                    }
                    operator delete(this->groupMembers.value);
                    this->groupMembers.value = values;
                    this->groupMembers.maximumSizeValue = newNumber;
                }
            }
            this->groupMembers.value[this->groupMembers.numberValue] = local_4;
            this->groupMembers.numberValue = this->groupMembers.numberValue + 1;
        group_member_found:
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    rge_read(save_file, &byte_val, 4);
    numberUnits = 0;
    if (0 < byte_val) {
        do {
            rge_read(save_file, &local_4, 4);
            int number = this->pathingGroupMembers.numberValue;
            int index = 0;
            tempInt_fffffff8 = local_4;
            for (; index < number && index < this->pathingGroupMembers.maximumSizeValue;
                 index = index + 1) {
                if (this->pathingGroupMembers.value[index] == local_4) {
                    goto pathing_member_found;
                }
            }
            if (number > this->pathingGroupMembers.maximumSizeValue - 1) {
                int newNumber = number + 1;
                int* values = (int*)operator new(newNumber * 4);
                if (values != 0) {
                    index = 0;
                    for (; index < this->pathingGroupMembers.maximumSizeValue && index < newNumber;
                         index = index + 1) {
                        values[index] = this->pathingGroupMembers.value[index];
                    }
                    operator delete(this->pathingGroupMembers.value);
                    this->pathingGroupMembers.value = values;
                    this->pathingGroupMembers.maximumSizeValue = newNumber;
                }
            }
            this->pathingGroupMembers.value[this->pathingGroupMembers.numberValue] = tempInt_fffffff8;
            this->pathingGroupMembers.numberValue = this->pathingGroupMembers.numberValue + 1;
        pathing_member_found:
            numberUnits = numberUnits + 1;
        } while (numberUnits < byte_val);
    }

    this->sprite_list = this->create_sprite_list();
    this->sprite_list->load(save_file, world->sprites);
    this->owner->world->add_object(this);

    if (this->sleep_flag != 0) {
        this->owner->sleeping_objects->add_node(this);
    } else if (this->dopple_flag != 0) {
        this->owner->doppleganger_objects->add_node(this);
    } else {
        this->owner->objects->add_node(this);
    }

    this->objects = this->create_object_list();
    this->selected = 0;
    return 1;
}
