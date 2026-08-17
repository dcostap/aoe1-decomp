// STATUS: EXACT CANDIDATE
// NOTE: A positive typed guard with one shared done label matches the late state-4/state-6
// return, direct state-7 return, retarget arm, and late null return in the original CFG.
// Attempt log:
// - The former naked function matched exactly but violated the no-inline-assembly policy.
// - The clean sequential guard source preserves the parameter load, two virtual calls,
//   saved registers, and all observed field offsets. It emits 69 bytes versus 81.
// - Explicit labels, duplicated retarget arms, switch forms, and state-return order
//   variants did not recover the original late null return or state-7 return island.
// - A positive non-null guard with duplicated retarget arms recovers the original
//   state-4/state-6/state-7 branch topology and 81-byte size, but VC5 emits xor edx,
//   cmp eax,edx, and mov [this+5A],dl instead of test eax,eax and mov byte,0.
// - Grouped state ORs, signed-char/bool flag types, '\\0'/false stores, NULL spellings,
//   an inline flag helper, empty null arms, and earlier label-flow variants did not change it.
// - The shared done label is the smallest natural source form that reproduces the proven
//   state-4/state-6 shared return without duplicating the retarget arm.
// - Main review replaced generic virtual slots with the canonical RGE_Action_Attack surface.
// VALIDATION: check_function.py --va 00401AD0 --rebuild --detail full => MATCH, 0.0000%.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Task;

class RGE_Action_Attack {
public:
    virtual ~RGE_Action_Attack();
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char attack_response(RGE_Static_Object* param_1);
    virtual unsigned char relation_response(long param_1, unsigned char param_2);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    int gap_04;
    int gap_08;
    unsigned char state;
    char gap_0D[0x03];
    RGE_Static_Object* target_obj;
    char gap_14[0x46];
    unsigned char indirect_fire_flag;
};

int RGE_Action_Attack::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    if (param_1 != 0) {
        if (param_1 == this->target_obj) {
            if (this->state == 4 || this->state == 6) {
                goto done;
            }
            if (this->state == 7) {
                return 1;
            }
        }

        this->indirect_fire_flag = 0;
        this->set_target_obj(param_1);
        this->set_state(4);

    done:
        return 1;
    }

    return 0;
}
