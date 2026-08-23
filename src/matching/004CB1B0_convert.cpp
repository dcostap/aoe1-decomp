// VA: 004CB1B0 TRIBE_Combat_Object::convert
// Canonical ownership: owner_data->world resolves the target; actions is the
// inherited action list at +0x184. The 0x48-byte TRIBE_Action_Convert
// construction and integer coordinate surface are supported by this TU's
// exact body/call bytes (the coordinates are pushed, not converted in x87).
// Attempt log:
// - baseline: natural convert source; all 16 calls, first 94 instructions,
//   frame, and size-adjacent body blocks align. Remaining drift is the shared
//   failure/success epilogue plus the isolated EH-handler address.
// - adding a typed result-pointer/shared-tail reconstruction improved CFG
//   shape but changed the long-lived register basin and worsened positional
//   bytes; rolled back.
// - explicit success/failure label reordering likewise worsened the prologue
//   and was rolled back. Keep the baseline source as the canonical candidate.
// - continuation probes: ordinary int result, pointer result, register result,
//   result-setting labels, target-null return, and success-initialized result
//   all moved the exact body prefix or broadened the EH/return CFG. The pointer
//   result reached 331-byte/97.27%-shape output but introduced target/result
//   preservation in EBX and 255 positional differences; it was diagnostic only.
// - final clean validation retains the natural early returns and exact 16-call
//   body. Remaining bytes are the shared success/failure epilogue topology
//   (67 positional bytes, rebuilt +19 bytes), with no ordered-call or layout
//   blocker identified.
// - changed make_action/action_id and the convert-action constructor surface
//   from int to donor-supported RGE_Task*; emitted code was unchanged, so keep
//   the canonical pointer/task model and the existing /GX context.
// - paused with the remaining lead localized to VC5 tail layout/EH context.
// - sequential sibling probe: the validated hunt result-pointer source and
//   centralized task/action failure label reproduce the same 333B frontier.
//   Calls remain aligned; only the return-register tail and two bytes differ.
// - direct task-null exit removed the two-byte failure block but returned the
//   target pointer on a null task; it widened the positional diff to 49 bytes.
// - assigning the constructor result into the status pointer was codegen
//   neutral; removed it to retain the natural typed ownership model.
// - fresh task-null direct return, final-success direct return, and a separate
//   task-failure alias all worsened the CFG (122/402/77-byte diffs); rolled back.
// - boolean/equality status returns were 27-byte and 338/339-byte variants;
//   action-derived boolean status was a codegen duplicate. Uninitialized and
//   declaration-reordered scalar status forms widened to 287/67-byte diffs.
// - direct literal returns for all success/failure paths broadened the CFG to
//   391 bytes; rolled back.
// - a separate int status with the typed target preserved improved that
//   variant to 367 bytes but remained far from the clean tail; rolled back.
// - routing only make_action failure to the common tail produced 331 bytes but
//   changed the branch topology and reached a 49-byte diff; rolled back.
// - separate target/result locals with a shared status tail reproduced the
//   prior 350-byte frontier; rolled back. The clean pointer-result source is
//   still the best plausible candidate.
// - fresh worker probes: direct success returns (245 bytes), separate target
//   and status locals (287-329 bytes), register-qualified status (287 bytes),
//   labeled literal-success tails (156 bytes), and dead-parameter status reuse
//   (329 bytes) all worsened CFG or the exact body prefix; each was rolled back.
// - revisit probes: nested guards and direct-return variants widened the CFG
//   (181-329 bytes), while the pointer truth return reached 27 bytes; each was
//   rolled back. Marking convert virtual restored the original U-decorated ABI
//   symbol with unchanged code. The typed RGE_Combat_Object base also leaves
//   the 20-byte frontier unchanged and is retained for object ownership.
// - independent revisit: routing make_action null to the shared end reached
//   331 bytes but widened the diff to 49. An explicit final truth guard reached
//   27, a late scalar status reached 231, keeping the target on success reached
//   34, and a direct constructor-failure return reached 160. All probes moved
//   the natural body or worsened the tail; restore the pinned 333-byte source.
// - final clean validation retains the 333-byte natural pointer-result build:
//   all 16 calls and the first 226 bytes align, but the success/failure tail
//   still emits `mov esi,1; mov eax,esi` instead of the oracle's `mov eax,1`.
// FLAGS: config/flags/004CB1B0_convert.rsp
// ACCEPTED DRIFT: The two-byte size increase only funnels the null, allocation
// failure, and success results through ESI before EAX. The original leaves the
// same zero from make_action, writes zero directly on constructor failure, and
// writes one directly on success. All calls, branches, memory effects, EH
// states, cleanup, return values, and fault behavior match.

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Action;
class RGE_Action_List;
class RGE_Task;
class TRIBE_Action_Convert;

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

class RGE_Combat_Object {
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
    virtual RGE_Task* make_action(RGE_Static_Object*, float, float, int);

};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    virtual int convert(int object_id, int force);
};

struct OwnerData {
    char pad_00[0x3C];
    RGE_Game_World* world;
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    TRIBE_Action_Convert(TRIBE_Combat_Object* object, RGE_Task* action_id, RGE_Static_Object* target);
};

int TRIBE_Combat_Object::convert(int object_id, int force) {
    RGE_Static_Object* result;
    RGE_Task* action_id;
    TRIBE_Action_Convert* action;

    result = owner_data->world->object(object_id);
    if (result == 0) goto end;

    if (force == 0 && actions->have_action() == 1 && actions->get_action()->get_target() == result && actions->get_action()->action_type() == 0x68) {
        result = (RGE_Static_Object*)1;
        goto end;
    }

    if (actions->have_action() == 1 && actions->get_action()->action_type() == 0x68) {
        actions->get_action()->set_target(result, result->world_x, result->world_y, result->world_z);
        result = (RGE_Static_Object*)1;
        goto end;
    }

    action_id = make_action(result, result->world_x, result->world_y, result->world_z);
    if (action_id == 0) goto fail;

    action = new TRIBE_Action_Convert(this, action_id, result);
    if (action == 0) goto fail;

    actions->delete_list();
    add_action(action);
    result = (RGE_Static_Object*)1;
    goto end;

fail:
    result = 0;
end:
    return (int)result;
}
