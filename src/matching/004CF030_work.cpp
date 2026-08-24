#ifndef TACT_HEA_CONTEXT_H
class RGE_Static_Object { public: void* vtable_ptr; long id; char pad_08[0x30]; float world_x; float world_y; float world_z; };
class RGE_Action { public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void first_in_stack(unsigned char);
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void set_target_obj(RGE_Static_Object*);
    short action_type; unsigned char pad_06[2]; void* obj; unsigned char state; unsigned char pad_0D[3]; RGE_Static_Object* target_obj; RGE_Static_Object* target_obj2; int targetID; int target2ID; float target_x; float target_y; float target_z;
};
class TRIBE_Action_Heal : public RGE_Action { public: int work(RGE_Static_Object* target, float, float, float); };
#endif
int TRIBE_Action_Heal::work(RGE_Static_Object* target, float, float, float) {
    if (target != 0) {
        if (target == this->target_obj) {
            unsigned char s = this->state;
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
