#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Action_Object;

class RGE_Static_Object {
public:
    char gap_04[0x4B];
    unsigned char worker_num;

    void set_sleep_flag(unsigned char enabled);
    virtual void set_being_worked_on(RGE_Action_Object* action, short mode, unsigned char flag);
};

#endif

void RGE_Static_Object::set_being_worked_on(RGE_Action_Object* action, short mode, unsigned char flag) {
    if (worker_num < 0xFA) {
        worker_num = worker_num + 1;
    }
    set_sleep_flag(0);
}
