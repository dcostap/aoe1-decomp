// VA: 00406300 RGE_Action_Object::move_to
// PDB source: act_obj.cpp lines 218-247
// Attempt log:
// - 2026-05-31: Replaced placeholder stub with natural /GX new-expression implementation
//   from the packet/decompiler. First baseline uses real member calls, RGE_Action_Move_To
//   size 0x44, and vtable padding to slot +0x208 for the final action enqueue.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_Move_To;
class UnitAIModule;

class RGE_Action_List {
public:
    int action_move_to(RGE_Static_Object* target, float x, float y, float z);
};

class UnitAIModule {
public:
    void setCurrentOrder(int order);
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int group, float x, float y, float z);
};

class RGE_Static_Object {
public:
    void* vtable;                 // +0x00
    int id;                       // +0x04
    void* master_obj;             // +0x08
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;           // +0x14
};

class RGE_Action_Move_To {
public:
    char gap_00[0x44];
    RGE_Action_Move_To(RGE_Action_Object* owner, RGE_Static_Object* target, float range, void* sprite);
    RGE_Action_Move_To(RGE_Action_Object* owner, float x, float y, float z, float range, void* sprite);
};

#define VPAD1(n) virtual void vpad##n(void);
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Action_Object {
public:
    VPAD64(0)
    VPAD32(64)
    VPAD16(96)
    VPAD16(112)
    VPAD2(128)
    virtual void set_action(RGE_Action_Move_To* action); // slot 130 / +0x208

    char gap_04[0x70];            // +0x04..+0x73
    UnitAIModule* unit_ai;        // +0x74
    char gap_78[0x10C];           // +0x78..+0x183
    RGE_Action_List* actions;     // +0x184
    unsigned char command_flag;   // +0x188

    void move_to(RGE_Static_Object* target, float x, float y, float z);
};

void RGE_Action_Object::move_to(RGE_Static_Object* target, float x, float y, float z)
{
    if ((RGE_Action_Object*)target != this) {
        if (this->actions->action_move_to(target, x, y, z) == 0) {
            RGE_Action_Move_To* action;

            if (target != 0) {
                action = new RGE_Action_Move_To(this, target, 0.4f, 0);
            } else {
                action = new RGE_Action_Move_To(this, x, y, z, 0.4f, 0);
            }

            if (this->unit_ai != 0) {
                this->unit_ai->setCurrentOrder(0x2C6);
                this->unit_ai->setCurrentAction(0x262);
                if (target != 0) {
                    this->unit_ai->setCurrentTarget(target->id,
                        ((RGE_Master_Static_Object*)target->master_obj)->object_group,
                        x, y, z);
                } else {
                    this->unit_ai->setCurrentTarget(-1, -1, x, y, z);
                }
            }

            if (action != 0) {
                this->set_action(action);
            }
            this->command_flag = this->command_flag + 1;
        }
    }
}
