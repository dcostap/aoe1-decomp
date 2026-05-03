// VA: 004CDB20 TRIBE_Action_Convert (72 B)
// PDB source: tact_cnv.cpp lines 90-102
//
// Blocker: VC5 scheduling differences for parameter loads.
// Original loads params in source order (task, fy, fx, fz).
// Our VC5 loads params in stack order (task, fx, fy, fz).
// Vftable override position also differs (after field_44 vs after fy).
// ~59/72 bytes match; remaining are store-ordering differences.

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
    float target_x;        // +0x20
    float target_y;        // +0x24
    float target_z;        // +0x28
    float timer;           // +0x2C
    RGE_Task* task;        // +0x30
    char gap_34[0x0C];     // +0x34 to +0x3F
    unsigned char field_40;// +0x40
    char gap_41[0x03];     // +0x41 to +0x43
    float requiredRange;   // +0x44

    TRIBE_Action_Convert(RGE_Action_Object* obj, RGE_Task* task, float fy, float fx, float fz);
};

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* obj, RGE_Task* task, float fy, float fx, float fz)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->target_y = fy;
    this->requiredRange = 1.0f;
    this->action_type = 0x68;
    this->target_x = fx;
    this->target_z = fz;
    this->field_40 = 0;
}
