// VA: 004D27A0 TRIBE_Action_Trade::TRIBE_Action_Trade (72B)
// PDB source: tact_trd.cpp lines 77-91
// give-up/pause after >10 focused attempts: direct member writes, raw int bit-casts, manual-vftable vs real-virtual surface,
// several init-list placements, explicit locals/register-shaping probes, raw-surface cast stores, and two focused variant_lab sweeps
// plus an additional focused constructor-shape brute-force pass over init-list/body-order combinations for task/x/y/z placement.
// 2026-05-04 resumed pass: the best basin improved by switching to the matched implicit-vptr class surface with `task(task)` in the init list.
// that version now matches the first 54 bytes exactly:
//   load y/task/x, store +24/+30, load z, mov eax,-1.0f, vftable, +40, +44
// remaining drift is only the late tail ordering:
//   original: type, +20, +28
//   rebuilt : +20, +28, type
// further focused sweeps over action_type spelling/placement and x/z localization all collapsed to the same 12/72 basin or worse.

class RGE_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    unsigned short action_type;
    char gap_06[0x1A];

    virtual ~RGE_Action();
    RGE_Action(RGE_Action_Object* obj, int value);
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    float field_20;
    float field_24;
    float field_28;
    char gap_2C[0x04];
    RGE_Task* task;
    char gap_34[0x0C];
    float pick_up_x;
    float pick_up_y;

    virtual ~TRIBE_Action_Trade();
    TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z);
};

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z)
    : RGE_Action(obj, 1), task(task)
{
    *(int*)&this->field_20 = *(int*)&x;
    *(int*)&this->field_24 = *(int*)&y;
    *(int*)&this->field_28 = *(int*)&z;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
    this->action_type = 0x6F;
}
