// 00403050 RGE_Action_Gather::first_in_stack
// Source: ACT_GATH.cpp lines 125-159, size 188 bytes
// Attempt log:
// first: extra ebx (temp var), movsx sign-ext on short, merged set_state paths, undersized by 12 bytes
// second: try matching register layout and code structure
// current: close control flow except rebuilt uses short `je` to final state-3 tail and is 12B smaller; original uses near `je` and keeps separate state-3 tails for param1==0 and target==0.
// tried positive guard + target local; got correct early branch family/size worse. Tried explicit master locals; no change. Remaining likely block-layout/tail-duplication source shape around two identical set_state(3) exits plus zero-constant relocation.

// VirtualHelper for RGE_Action_Object vtable+0x80 (slot 32)
struct ObjVHelper {
    virtual void _d0();   virtual void _d1();   virtual void _d2();   virtual void _d3();
    virtual void _d4();   virtual void _d5();   virtual void _d6();   virtual void _d7();
    virtual void _d8();   virtual void _d9();   virtual void _d10();  virtual void _d11();
    virtual void _d12();  virtual void _d13();  virtual void _d14();  virtual void _d15();
    virtual void _d16();  virtual void _d17();  virtual void _d18();  virtual void _d19();
    virtual void _d20();  virtual void _d21();  virtual void _d22();  virtual void _d23();
    virtual void _d24();  virtual void _d25();  virtual void _d26();  virtual void _d27();
    virtual void _d28();  virtual void _d29();  virtual void _d30();  virtual void _d31();
    virtual void v80(short val, int flag);  // +0x80 = slot 32
};

// RGE_Action base class (from matching 00402EA0)
class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* param_1);
    virtual int vf08(int param_1, RGE_Action_Object* param_2);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int param_1);
    virtual short vf18(void);
    virtual void vf1C(unsigned char param_1);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);
    virtual unsigned char vf38(void*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C(void);
    virtual void* vf50(void);
    virtual void set_target_obj(void*);    // +0x54
    virtual void vf58(void*);              // +0x58
    virtual void set_state(unsigned char); // +0x5C

    short action_type;              // +0x04
    char gap_06[2];                 // +0x06
    RGE_Action_Object* obj;         // +0x08
    unsigned char state;            // +0x0C
    char gap_0D[3];                 // +0x0D
    void* target_obj;               // +0x10
    void* target_obj2;              // +0x14
    int targetID;                   // +0x18
    int target2ID;                  // +0x1C
    float target_x;                 // +0x20
    float target_y;                 // +0x24
    float target_z;                 // +0x28
    float timer;                    // +0x2C
    void* task;                     // +0x30
    void* sub_actions;              // +0x34
    void* sprite;                   // +0x38
    unsigned char subActionValue;   // +0x3C
    char gap_3D[3];                 // +0x3D
};

class RGE_Action_Gather : public RGE_Action {
public:
    int targetType;                 // +0x40

    void first_in_stack(unsigned char param1);
};

void RGE_Action_Gather::first_in_stack(unsigned char param1) {
    if (*(short*)((char*)this->obj + 0x4C) != *(short*)((char*)this->task + 0x14)) {
        ((ObjVHelper*)this->obj)->v80(*(short*)((char*)this->task + 0x14), 0);
    }

    if (param1 != 0) {
        void* target = this->target_obj;
        if (target != 0) {
            if (*(int*)((char*)target + 0x0C) == *(int*)((char*)this->obj + 0x0C)) {
                int targ_master = *(int*)((char*)target + 0x08);
                int obj_master = *(int*)((char*)this->obj + 0x08);
                short s = *(short*)(targ_master + 0x10);

                if ((s == *(short*)(obj_master + 0xE8) ||
                     s == *(short*)(obj_master + 0xEA)) &&
                    *(float*)((char*)this->obj + 0x44) > 0.0f) {
                    this->vf58(target);
                    this->set_target_obj(0);
                    this->target_x = -1.0f;
                    this->target_y = -1.0f;
                    this->target_z = -1.0f;
                    this->set_state(8);
                    return;
                }
            }
            this->set_state(4);
            return;
        }
    }
    this->set_state(3);
}
