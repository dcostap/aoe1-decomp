class RGE_Static_Object;

class RGE_Action {
public:
    virtual RGE_Static_Object* get_target_obj(void);

    char gap_04[0x0C];
    RGE_Static_Object* target_obj;
};

RGE_Static_Object* RGE_Action::get_target_obj(void) {
    return this->target_obj;
}
