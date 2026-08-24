// 00403050 RGE_Action_Gather::first_in_stack
// Source: ACT_GATH.cpp lines 125-159, size 188 bytes
// Attempt log:
// first: extra ebx (temp var), movsx sign-ext on short, merged set_state paths, undersized by 12 bytes
// second: try matching register layout and code structure
// baseline: canonical ACT_GATH ownership and natural virtual calls, but the compiler merged the two state-3 exits (170 emitted bytes).
// external zero global alone was unchanged; an explicit target-null early-return put its state-3 call inline and worsened CFG layout.
// explicit target-nonnull/target-null else plus separate param1-false tail restored the two original state-3 blocks and exact size.
// typed object/master fields replaced raw proven offsets without changing exact codegen; retained as the cleaner source reconstruction.

#ifndef ACT_GATH_CONTEXT_H
extern float DAT_0056e278;

// Binary-proven object surface used by the action's attribute/ownership checks.
class RGE_Task {
public:
    char gap_00[0x14];
    short attribute_type;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;                    // +0x10
    char gap_12[0xD6];
    short drop_site;             // +0xE8
    short backup_drop_site;      // +0xEA
};

class RGE_Action_Object {
public:
    virtual void _d0();   virtual void _d1();   virtual void _d2();   virtual void _d3();
    virtual void _d4();   virtual void _d5();   virtual void _d6();   virtual void _d7();
    virtual void _d8();   virtual void _d9();   virtual void _d10();  virtual void _d11();
    virtual void _d12();  virtual void _d13();  virtual void _d14();  virtual void _d15();
    virtual void _d16();  virtual void _d17();  virtual void _d18();  virtual void _d19();
    virtual void _d20();  virtual void _d21();  virtual void _d22();  virtual void _d23();
    virtual void _d24();  virtual void _d25();  virtual void _d26();  virtual void _d27();
    virtual void _d28();  virtual void _d29();  virtual void _d30();  virtual void _d31();
    virtual void set_attribute(short val, int flag);  // +0x80 = slot 32
    char gap_04[0x04];
    RGE_Master_Static_Object* master_obj;  // +0x08
    void* owner;                            // +0x0C
    char gap_10[0x34];
    float attribute_amount_held;            // +0x44
    char gap_48[0x04];
    short attribute_type_held;              // +0x4C
};

// RGE_Action base class (from matching 00402EA0)
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
    virtual void set_target_obj2(void*);   // +0x58
    virtual void set_state(unsigned char); // +0x5C

    short action_type;              // +0x04
    char gap_06[2];                 // +0x06
    RGE_Action_Object* obj;         // +0x08
    unsigned char state;            // +0x0C
    char gap_0D[3];                 // +0x0D
    RGE_Action_Object* target_obj;  // +0x10
    void* target_obj2;              // +0x14
    int targetID;                   // +0x18
    int target2ID;                  // +0x1C
    float target_x;                 // +0x20
    float target_y;                 // +0x24
    float target_z;                 // +0x28
    float timer;                    // +0x2C
    RGE_Task* task;                 // +0x30
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
#endif

void RGE_Action_Gather::first_in_stack(unsigned char param1) {
    short attr = this->task->attribute_type;
    if (this->obj->attribute_type_held != attr) {
        this->obj->set_attribute(attr, 0);
    }

    if (param1 != 0) {
#ifdef ACT_GATH_CONTEXT_H
        RGE_Static_Object* target = this->target_obj;
#else
        RGE_Action_Object* target = this->target_obj;
#endif
        if (target != 0) {
            if (target->owner == this->obj->owner) {
                RGE_Master_Static_Object* targ_master = target->master_obj;
                RGE_Master_Static_Object* obj_master = this->obj->master_obj;
                short s = targ_master->id;

                if ((s == obj_master->drop_site ||
                     s == obj_master->backup_drop_site) &&
                    this->obj->attribute_amount_held > DAT_0056e278) {
                    this->set_target_obj2(target);
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
        } else {
            this->set_state(3);
            return;
        }
    }
    this->set_state(3);
}
