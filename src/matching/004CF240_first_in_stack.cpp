// 004CF240 TRIBE_Action_Hunt::first_in_stack(unsigned char) — tact_hnt.cpp:139-171
// PDB source: C:\msdev\work\age1_x1\tact_hnt.cpp

#ifndef TACT_HNT_SHARED_CONTEXT
class RGE_Task {
public:
    char gap_00[0x14];
    short attribute_type;  // +0x14
};

class MasterStub {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0xA6];
};

class MasterActionStub : public MasterStub {
public:
    char gap_B8[0x30];
    short drop_site;              // +0xE8
    short backup_drop_site;       // +0xEA
};

class UnitStub {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void set_attribute(short param1, float param2);

    char gap_04[0x04];
    MasterStub* master_obj;        // +0x08
    void* owner;                   // +0x0C
    char gap_10[0x34];
    float attribute_amount_held;   // +0x44
    char gap_48[0x04];
    short attribute_type_held;     // +0x4C
};
#endif

// A global float = 0.0 used for fcomp comparison
// Non-const so VC5 generates an actual memory reference
float _zero_val = 0.0f;

#ifndef TACT_HNT_SHARED_CONTEXT
class TRIBE_Action_Hunt {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void first_in_stack(unsigned char param_1);
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void set_target_obj(void* obj);
    virtual void set_target_obj2(void* obj);
    virtual void set_state(int val);

    short action_type;             // +0x04
    unsigned char _pad_06[2];
    UnitStub* obj;                 // +0x08
    unsigned char state;           // +0x0C
    unsigned char _pad_0D[3];
    UnitStub* target_obj;          // +0x10
    UnitStub* target_obj2;         // +0x14
    int targetID;                  // +0x18
    int target2ID;                 // +0x1C
    float target_x;                // +0x20
    float target_y;                // +0x24
    float target_z;                // +0x28
    float timer;                   // +0x2C
    void* task;                    // +0x30
    void* sub_actions;             // +0x34
    void* sprite;                  // +0x38
    unsigned char subActionValue;  // +0x3C
    unsigned char _pad_3D[3];
    int targetType;                // +0x40
};
#else
typedef RGE_Master_Static_Object MasterStub;
typedef RGE_Master_Action_Object MasterActionStub;
typedef RGE_Static_Object UnitStub;
#endif

void TRIBE_Action_Hunt::first_in_stack(unsigned char param_1)
{
    RGE_Task* tsk = (RGE_Task*)this->task;

    short attr_val = tsk->attribute_type;
    if (this->obj->attribute_type_held != attr_val) {
        this->obj->set_attribute(attr_val, 0.0f);
    }

    if (param_1) {
        UnitStub* target = this->target_obj;
        if (target) {
            UnitStub* unit = this->obj;
            // Compare target->owner with unit->owner (order matters for register choice)
            if (target->owner == unit->owner) {
                MasterStub* target_master = target->master_obj;
                MasterActionStub* unit_master = (MasterActionStub*)unit->master_obj;
                short target_id = target_master->id;
                if (target_id == unit_master->drop_site || target_id == unit_master->backup_drop_site) {
                    if (unit->attribute_amount_held > _zero_val) {
                        this->set_target_obj2(target);
                        this->set_target_obj(0);
                        this->target_x = -1.0f;
                        this->target_y = -1.0f;
                        this->target_z = -1.0f;
                        this->set_state(8);
                        return;
                    }
                }
            }
            this->set_state(4);
        } else {
            this->set_state(3);
        }
    } else {
        this->set_state(3);
    }
}
