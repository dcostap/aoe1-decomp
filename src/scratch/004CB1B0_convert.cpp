// VA: 004CB1B0 TRIBE_Combat_Object::convert
// First pass from packet; same source family as TRIBE_Combat_Object::hunt.
// Action type 0x68 (convert), sizeof 0x48, TRIBE_Action_Convert ctor.
// Compiles with /GX; register, vtable, sizeof all correct.
// Remaining: 12.4% positional diff is (a) SEH handler placeholder (link-time),
// (b) inline epilogue for last return-0 vs shared epilogue (same issue as hunt).
// FLAGS: config/flags/004CB1B0_convert.rsp

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Action;
class RGE_Action_List;
class TRIBE_Action_Convert;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    void* vtable;
    char pad_04[0x34];
    float world_x;
    float world_y;
    int world_z;
};

class RGE_Action {
public:
    RGE_Action(void* obj, int a);
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual short action_type();
    virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28();
    virtual void vf2C(); virtual void vf30();
    virtual void set_target(RGE_Static_Object*, float, float, int);
    virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44();
    virtual void vf48(); virtual RGE_Static_Object* get_target();

    short field_04;           // +0x04
    char gap_06[0x1A];
    int target_x;             // +0x20
    int target_y;             // +0x24
    int target_z;             // +0x28
    char gap_2C[4];
    void* task_ptr;           // +0x30
    char gap_34[0x0C];
    char was_same_owner;      // +0x40
    char gap_41[3];
    float required_range;     // +0x44
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
};

class TRIBE_Combat_Object {
public:
    virtual void vf000();
    char pad_004[0x0C - 0x04];
    struct OwnerData* owner_data;
    char pad_010[0x184 - 0x10];
    RGE_Action_List* actions;

    virtual void pad004(); virtual void pad008(); virtual void pad00C(); virtual void pad010();
    virtual void pad014(); virtual void pad018(); virtual void pad01C(); virtual void pad020();
    virtual void pad024(); virtual void pad028(); virtual void pad02C(); virtual void pad030();
    virtual void pad034(); virtual void pad038(); virtual void pad03C(); virtual void pad040();
    virtual void pad044(); virtual void pad048(); virtual void pad04C(); virtual void pad050();
    virtual void pad054(); virtual void pad058(); virtual void pad05C(); virtual void pad060();
    virtual void pad064(); virtual void pad068(); virtual void pad06C(); virtual void pad070();
    virtual void pad074(); virtual void pad078(); virtual void pad07C(); virtual void pad080();
    virtual void pad084(); virtual void pad088(); virtual void pad08C(); virtual void pad090();
    virtual void pad094(); virtual void pad098(); virtual void pad09C(); virtual void pad0A0();
    virtual void pad0A4(); virtual void pad0A8(); virtual void pad0AC(); virtual void pad0B0();
    virtual void pad0B4(); virtual void pad0B8(); virtual void pad0BC(); virtual void pad0C0();
    virtual void pad0C4(); virtual void pad0C8(); virtual void pad0CC(); virtual void pad0D0();
    virtual void pad0D4(); virtual void pad0D8(); virtual void pad0DC(); virtual void pad0E0();
    virtual void pad0E4(); virtual void pad0E8(); virtual void pad0EC(); virtual void pad0F0();
    virtual void pad0F4(); virtual void pad0F8(); virtual void pad0FC(); virtual void pad100();
    virtual void pad104(); virtual void pad108(); virtual void pad10C(); virtual void pad110();
    virtual void pad114(); virtual void pad118(); virtual void pad11C(); virtual void pad120();
    virtual void pad124(); virtual void pad128(); virtual void pad12C(); virtual void pad130();
    virtual void pad134(); virtual void pad138(); virtual void pad13C(); virtual void pad140();
    virtual void pad144(); virtual void pad148(); virtual void pad14C(); virtual void pad150();
    virtual void pad154(); virtual void pad158(); virtual void pad15C(); virtual void pad160();
    virtual void pad164(); virtual void pad168(); virtual void pad16C(); virtual void pad170();
    virtual void pad174(); virtual void pad178(); virtual void pad17C(); virtual void pad180();
    virtual void pad184(); virtual void pad188(); virtual void pad18C(); virtual void pad190();
    virtual void pad194(); virtual void pad198(); virtual void pad19C(); virtual void pad1A0();
    virtual void pad1A4(); virtual void pad1A8(); virtual void pad1AC(); virtual void pad1B0();
    virtual void pad1B4(); virtual void pad1B8(); virtual void pad1BC(); virtual void pad1C0();
    virtual void pad1C4(); virtual void pad1C8(); virtual void pad1CC(); virtual void pad1D0();
    virtual void pad1D4(); virtual void pad1D8(); virtual void pad1DC(); virtual void pad1E0();
    virtual void pad1E4(); virtual void pad1E8(); virtual void pad1EC(); virtual void pad1F0();
    virtual void pad1F4(); virtual void pad1F8(); virtual void pad1FC(); virtual void pad200();
    virtual void pad204();
    virtual void add_action(RGE_Action* action);
    virtual void pad20C();
    virtual int make_action(RGE_Static_Object*, float, float, int);

    int convert(int object_id, int force);
};

struct OwnerData {
    char pad_00[0x3C];
    RGE_Game_World* world;
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    TRIBE_Action_Convert(TRIBE_Combat_Object* object, int action_id, RGE_Static_Object* target);
};

int TRIBE_Combat_Object::convert(int object_id, int force) {
    RGE_Static_Object* target;
    int action_id;
    TRIBE_Action_Convert* new_action;

    target = owner_data->world->object(object_id);
    if (target == 0) goto end;

    if (force == 0 && actions->have_action() == 1 && actions->get_action()->get_target() == target && actions->get_action()->action_type() == 0x68) {
        return 1;
    }

    if (actions->have_action() == 1 && actions->get_action()->action_type() == 0x68) {
        actions->get_action()->set_target(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    action_id = make_action(target, target->world_x, target->world_y, target->world_z);
    if (action_id == 0) goto end;

    new_action = new TRIBE_Action_Convert(this, action_id, target);
    if (new_action == 0) goto end;

    actions->delete_list();
    add_action(new_action);
    return 1;

end:
    return 0;
}
