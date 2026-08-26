#ifndef PLAYER_GROUPED_TU
class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual void copy_obj(void);
    virtual void modify(void);
    virtual void modify_delta(void);
    virtual void modify_percent(void);
    virtual void save(void);
    virtual void make_new_master(void);
    virtual RGE_Static_Object* make_new_obj(void* player, float x, float y, float z);
};
#endif

#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;

    virtual RGE_Static_Object* make_new_object(long id, float x, float y, float z, int unused);
};
#endif

RGE_Static_Object* RGE_Player::make_new_object(long id, float x, float y, float z, int unused) {
    if ((id >= 0) && (this->master_objects[id] != 0)) {
        return this->master_objects[id]->make_new_obj(this, x, y, z);
    }
    return 0;
}
