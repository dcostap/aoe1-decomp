// VA: 0045A950 RGE_Missile_Object::init_missile (137 B)
// Attempt log:
// inherited: no EH without ctor-shaped new; try/catch gave EBP EH; /GX present.
// try 1: use real RGE_Action_Missile constructor in new expression instead of new+init.

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
struct RGE_Action_Object { void* vtable; };
struct RGE_Combat_Object { void* vtable; };
struct RGE_Static_Object {
    void* vtable;
    char gap_04[0x34];
    float world_x;
    float world_y;
    float world_z;
};

struct RGE_Action_Missile : RGE_Action_Object {
    char pad[0x50];
    RGE_Action_Missile(RGE_Action_Object* owner, RGE_Combat_Object* target,
                       RGE_Static_Object* src_obj, float wx, float wy, float wz);
    ~RGE_Action_Missile();
};

struct RGE_Action_List { void add_action(RGE_Action_Object* action); };

struct RGE_Missile_Object {
    void* vtable;
    char gap_04[0x180];
    RGE_Action_List* action_list;
    char pad_188_to_1C4[0x3C];
    float max_range;
    void init_missile(RGE_Combat_Object* target, RGE_Static_Object* src_obj, float range);
};
#endif

void RGE_Missile_Object::init_missile(RGE_Combat_Object* target, RGE_Static_Object* src_obj, float range)
{
    RGE_Action_Missile* obj = new RGE_Action_Missile((RGE_Action_Object*)this, target, src_obj,
                                                      src_obj->world_x, src_obj->world_y, src_obj->world_z);
    if (obj) {
        this->action_list->add_action(obj);
    }
    this->max_range = range;
}
