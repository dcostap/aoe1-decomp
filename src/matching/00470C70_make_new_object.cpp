#ifndef PLAYER_GROUPED_TU
class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual void copy_obj(void);
    virtual void modify(void);
    virtual void modify_delta(void);
    virtual void modify_percent(void);
    virtual void save(void);
    virtual void make_new_master(void);
    virtual void* make_new_obj(void* player, float x, float y, float z);
};
#endif

#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;

    void* make_new_object(long id, float x, float y, float z, int unused);
};
#endif

void* RGE_Player::make_new_object(long id, float x, float y, float z, int unused) {
    if ((id >= 0) && (this->master_objects[id] != 0)) {
        return this->master_objects[id]->make_new_obj(this, x, y, z);
    }
    return 0;
}
