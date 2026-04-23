class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void* create(RGE_Player* player, float x, float y, float z);
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects;

    void* make_new_object(long id, float x, float y, float z, int unused);
};

void* RGE_Player::make_new_object(long id, float x, float y, float z, int unused) {
    if ((id >= 0) && (this->master_objects[id] != 0)) {
        return this->master_objects[id]->create(this, x, y, z);
    }
    return 0;
}
