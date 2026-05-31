// VA: 00406860 RGE_Action_Object::get_command_master
// PDB source: act_obj.cpp lines 484-519
// Attempt log:
// - 2026-05-31: Replaced placeholder stub with natural master fallback scan using the
//   binary-observed +0xD8 vtable helper slot and +0x0C master-list owner. Initial
//   direct loop was close but used EBP for target and EBX for loop counter.
// - while(1)/continue/goto-found fixed the late success/exhausted-tail topology but
//   still leaves the target-vs-counter register color swapped (target in EBP, i in EBX).
// - Tried mutating the incoming target parameter into the loop counter to mimic the
//   reused stack slot; one form preloaded EDX before push ebx, another moved target
//   through ESI/EBP. Tried volatile i; it produced the correct early EBX target load
//   but added too many stack-memory ops. Restored the cleaner target-local baseline.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Master_Static_Object;

class RGE_Master_Command {
public:
    virtual void vf00(void);
    virtual int get_command_master(RGE_Action_Object* action, RGE_Static_Object* target,
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

class RGE_Action_Object {
public:
    char gap_00[8];                  // +0x00..+0x07
    RGE_Master_Static_Object* master; // +0x08
    RGE_Master_List* master_list;    // +0x0C

    RGE_Master_Static_Object* get_command_master(RGE_Static_Object* target, float x, float y, float z);
};

RGE_Master_Static_Object* RGE_Action_Object::get_command_master(RGE_Static_Object* target,
                                                                float x, float y, float z)
{
    RGE_Static_Object* target_obj = target;

    if ((RGE_Action_Object*)target_obj != this && this->master->commandable != 0) {
        if (this->master->command->get_command_master(this, target_obj, x, y, z) != 0) {
            return this->master;
        }

        if (this->master->commandable != 0) {
            int i = 0;
            if (this->master_list->master_count > 0) {
                RGE_Master_Static_Object* obj;
                while (1) {
                    obj = this->master_list->masters[i];
                    if (obj != 0 &&
                        obj->object_group == this->master->object_group &&
                        obj->master_type == this->master->master_type &&
                        obj->commandable == this->master->commandable) {
                        if (obj->command->get_command_master(this, target_obj, x, y, z) != 0) {
                            goto found;
                        }
                    }
                    i++;
                    if (i < this->master_list->master_count) continue;
                    return this->master;
                }
found:
                return obj;
            }
        }
    }
    return this->master;
}
