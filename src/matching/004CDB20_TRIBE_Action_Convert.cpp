// VA: 004CDB20 TRIBE_Action_Convert (72 B)
// PDB source: tact_cnv.cpp lines 90-102
//
// tried the fuller matched-sibling RGE_Action surface; it moved the hidden vftable store too early and got worse.
// tried reduced-base body order variants, duplicate x stores, comma-expression chaining, and saved_x/saved_y locals.
// exact basin: keep `requiredRange(1.0f)` in the init list and use body order `task, action_type, target_x, target_y, target_z, field_40`.

#ifndef TACT_CNV_SHARED_CONTEXT
class RGE_Action_Object;
class RGE_Task;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(RGE_Action_Object* object, int doSetup);

    unsigned short action_type;
    char gap_06[0x1A];
};

class TRIBE_Action_Convert : public RGE_Action {
public:
    float target_x;         // +0x20
    float target_y;         // +0x24
    float target_z;         // +0x28
    float timer;            // +0x2C
    RGE_Task* task;         // +0x30
    char gap_34[0x0C];      // +0x34 to +0x3F
    unsigned char field_40; // +0x40
    char gap_41[0x03];      // +0x41 to +0x43
    float requiredRange;    // +0x44

    TRIBE_Action_Convert(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z);
};

#endif

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* obj, RGE_Task* task, float x, float y, float z)
    : RGE_Action(obj, 1), requiredRange(1.0f) {
    this->task = task;
    this->action_type = 0x68;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->field_40 = 0;
}
