#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Player;

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Player* owner;
    char gap_10[0x20];
    int hp;
    char gap_34[0x02];
    unsigned char selected;

    void set_sleep_flag(unsigned char value);
    virtual void die_die_die(void);
};

class RGE_Player {
public:
    void unselect_one_object(RGE_Static_Object* object);
};
#endif

void RGE_Static_Object::die_die_die(void) {
    if ((this->selected & 1) != 0) {
        this->owner->unselect_one_object(this);
    }
    this->set_sleep_flag(0);
    this->hp = 0;
}
