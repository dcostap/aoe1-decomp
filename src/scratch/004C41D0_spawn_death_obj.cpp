class RGE_Player;
class RGE_Static_Object;

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual RGE_Static_Object* vf18(RGE_Player* owner, float x, float y, float z);

    unsigned char master_type;
    char gap_05[0x43];
    short death_spawn_obj_id;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    RGE_Static_Object* spawn_death_obj(void);
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;
};
#endif

RGE_Static_Object* RGE_Static_Object::spawn_death_obj(void) {
    short id = this->master_obj->death_spawn_obj_id;
    if (id >= 0) {
        RGE_Master_Static_Object* master = this->owner->master_objects[id];
        if (master != 0) {
            return master->vf18(this->owner, this->world_x, this->world_y, this->world_z);
        }
    }
    return 0;
}
