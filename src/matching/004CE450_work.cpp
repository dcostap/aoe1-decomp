#ifndef TACT_CNV_SHARED_CONTEXT
typedef unsigned char uchar;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Master_Action_Object;
class RGE_Task;
class RGE_Static_Object { public: virtual ~RGE_Static_Object(); long id; char pad_08[0x30]; float world_x; float world_y; float world_z; };
class RGE_Action { public:
    virtual ~RGE_Action(); virtual int setup(RGE_Action_Object*); virtual int setup(int, RGE_Action_Object*); virtual RGE_Action_List* create_action_list(RGE_Action_Object*); virtual void rehook(); virtual void save(int); virtual short type(); virtual void first_in_stack(uchar);
    virtual unsigned char inside_obj_update(); virtual unsigned char idle_update(); virtual unsigned char update(); virtual int stop(); virtual int move_to(RGE_Static_Object*, float, float, float); virtual int work(RGE_Static_Object*, float, float, float); virtual unsigned char attack_response(RGE_Static_Object*); virtual unsigned char relation_response(long, unsigned char); virtual void copy_obj(RGE_Master_Action_Object*); virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*); virtual void get_state_name(char*); virtual RGE_Static_Object* get_target_obj(); virtual RGE_Static_Object* get_target_obj2(); virtual void set_target_obj(RGE_Static_Object*);
    short action_type; uchar pad_06[2]; void* obj; uchar state; uchar pad_0D[3]; RGE_Static_Object* target_obj; RGE_Static_Object* target_obj2; int targetID; int target2ID; float target_x; float target_y; float target_z;
};
class TRIBE_Action_Convert : public RGE_Action { public: uchar was_same_owner; char gap_41[3]; float requiredRange; int work(RGE_Static_Object* target, float, float, float); };
#endif

int TRIBE_Action_Convert::work(RGE_Static_Object* target, float, float, float) {
    if (target != 0) {
        if (target == this->target_obj) {
            uchar s = this->state;
            if (s == 4 || s == 6 || s == 7) return 1;
        }
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->first_in_stack(1);
        return 1;
    }
    return 0;
}
