class RGE_Static_Object;

class RGE_Action {
public:
    virtual RGE_Static_Object* get_target_obj2(void);

    char gap_04[0x10];
    RGE_Static_Object* target_obj2;
};

RGE_Static_Object* RGE_Action::get_target_obj2(void) {
    return this->target_obj2;
}
