// VA: 004CB060 TRIBE_Combat_Object::hunt
// Canonical ownership: owner_data->world resolves the target; actions is the
// inherited action list at +0x184; RGE_Action_Hunt is the proven 0x44-byte
// task/action object. Keep the body in the natural convert-style form: typed
// task/action locals with direct success and failure returns.
// Attempt log:
// - prior baseline: natural action-list hunt with /GX; early returns caused a
//   broad shared-tail mismatch and the initial action slots were eight bytes
//   early.
// - corrected delete_list, +0x208/+0x210 virtual slots, RGE_Action's virtual
//   destructor, 0x44-byte hunt-action layout, and float x/y/z ABI surfaces.
// - natural convert-style normalization removes the persistent result pointer
//   and keeps typed task/action locals with direct success/failure paths.
// - baseline result: 350 rebuilt bytes versus 331, diff 67, 90% exact-block
//   coverage, and all 16 calls aligned. The remaining drift is the failure
//   tail: the natural direct return emits an early cleanup instead of the
//   original failure block before the shared epilogue.
// - review readiness: keep this natural source. Remaining work is localized
//   tail/EH layout, not ownership, calls, or action ABI.
// FLAGS: config/flags/004CB060_hunt.rsp

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Action;
class RGE_Action_List;
class TRIBE_Action_Hunt;
class RGE_Task;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char pad_04[0x34];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual short action_type();
    virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28();
    virtual void vf2C(); virtual void vf30();
    virtual void set_target(RGE_Static_Object*, float, float, float);
    virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44();
    virtual void vf48(); virtual RGE_Static_Object* get_target();
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
    virtual RGE_Task* make_action(RGE_Static_Object*, float, float, float);

    int hunt(int object_id, int force);
};

struct OwnerData {
    char pad_00[0x3C];
    RGE_Game_World* world;
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    char gap_04[0x3C];
    int target_type;

    TRIBE_Action_Hunt(TRIBE_Combat_Object* object, RGE_Task* action_id,
                      RGE_Static_Object* target);
};

int TRIBE_Combat_Object::hunt(int object_id, int force) {
    RGE_Static_Object* target;
    RGE_Task* action_id;
    TRIBE_Action_Hunt* new_action;

    target = owner_data->world->object(object_id);
    if (target == 0) goto end;

    if (force == 0 && actions->have_action() == 1 && actions->get_action()->get_target() == target && actions->get_action()->action_type() == 0x6E) {
        return 1;
    }

    if (actions->have_action() == 1 && actions->get_action()->action_type() == 0x6E) {
        actions->get_action()->set_target(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    action_id = make_action(target, target->world_x, target->world_y, target->world_z);
    if (action_id == 0) goto end;

    new_action = new TRIBE_Action_Hunt(this, action_id, target);
    if (new_action == 0) goto end;

    actions->delete_list();
    add_action(new_action);
    return 1;

end:
    return 0;
}
