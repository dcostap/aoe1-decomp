// VA: 00406C30 RGE_Action_Object::getTask
// PDB source: act_obj.cpp lines 764-797
// Attempt log:
// - 2026-05-31: Replaced placeholder stub with natural master/candidate task lookup.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Master_Static_Object;
class RGE_Task;

class RGE_Master_Command {
public:
    virtual void vf00(void);
    virtual RGE_Task* getTask(RGE_Action_Object* action, RGE_Static_Object* target,
                              float x, float y, float z);
};

class RGE_Master_Static_Object {
public:
    char gap_00[4];                  // +0x00
    unsigned char master_type;       // +0x04
    char gap_05[0x0F];               // +0x05..+0x13
    short object_group;              // +0x14
    char gap_16[0xC2];               // +0x16..+0xD7
    RGE_Master_Command* command;     // +0xD8
    char gap_DC[0x10];               // +0xDC..+0xEB
    unsigned char commandable;       // +0xEC
};

class RGE_Master_List {
public:
    char gap_00[0x22];               // +0x00..+0x21
    short master_count;              // +0x22
    RGE_Master_Static_Object** masters; // +0x24
};

#define VPAD1(n) virtual void vpad##n(void);
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Action_Object {
public:
    VPAD16(0)
    VPAD4(16)
    VPAD1(20)
    virtual void set_command_master(RGE_Master_Static_Object* master); // slot 21 / +0x54

    char gap_04[4];                  // +0x04..+0x07
    RGE_Master_Static_Object* master; // +0x08
    RGE_Master_List* master_list;    // +0x0C

    RGE_Task* getTask(RGE_Static_Object* target, float x, float y, float z);
};

RGE_Task* RGE_Action_Object::getTask(RGE_Static_Object* target, float x, float y, float z)
{
    RGE_Task* task = this->master->command->getTask(this, target, x, y, z);
    if (task == 0 && this->master->commandable != 0) {
        int i = 0;
        if (this->master_list->master_count > 0) {
            RGE_Master_Static_Object* obj;
            while (1) {
                obj = this->master_list->masters[i];
                if (obj != 0 &&
                    obj->object_group == this->master->object_group &&
                    obj->master_type == this->master->master_type &&
                    obj->commandable == this->master->commandable) {
                    task = obj->command->getTask(this, target, x, y, z);
                    if (task != 0) {
                        goto found;
                    }
                }
                i++;
                if (i < this->master_list->master_count) continue;
                return task;
            }
found:
            this->set_command_master(obj);
        }
    }
    return task;
}
