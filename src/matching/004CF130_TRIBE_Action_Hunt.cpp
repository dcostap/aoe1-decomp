// 004CF130 TRIBE_Action_Hunt (constructor, 140 bytes) — MATCHED
// PDB: tact_hnt.cpp (TRIBE_Action_Hunt::TRIBE_Action_Hunt)

class RGE_Action_Object;
class RGE_Task;

class RGE_Master_Static_Object {
public:
    char gap_10[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_8[8];
    RGE_Master_Static_Object* master_obj;  // +0x8
    char gap_C[0x2C];   // +0xC to +0x37
    int world_x;         // +0x38
    int world_y;         // +0x3C
    int world_z;         // +0x40
    char gap_44[4];      // +0x44
    unsigned char object_state;   // +0x48
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    char gap_04[0x14];
    int targetID;       // +0x18
    int target2ID;      // +0x1C
    int world_x;        // +0x20
    int world_y;        // +0x24
    int world_z;        // +0x28
    char gap_2C[4];     // +0x2C
    int task;           // +0x30
    char gap_34[0xC];   // +0x34 to +0x3F
    int targetType;     // +0x40

    RGE_Action(RGE_Action_Object* obj, int do_setup);
    void set_target_obj(RGE_Static_Object* obj);
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    TRIBE_Action_Hunt(RGE_Action_Object* obj, RGE_Task* tsk, RGE_Static_Object* target);
};

TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* obj, RGE_Task* tsk, RGE_Static_Object* target)
    : RGE_Action(obj, 1)
{
    this->task = (int)tsk;
    *(int*)this = 0x5750F0;
    *(short*)&((char*)this)[4] = 0x6E;
    this->set_target_obj(target);
    if (target && target->object_state < 7) {
        this->world_x = target->world_x;
        this->world_y = target->world_y;
        this->world_z = target->world_z;
        this->targetType = target->master_obj->id;
    }
}
