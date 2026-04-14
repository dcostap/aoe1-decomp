class RGE_Static_Object {
public:
    virtual RGE_Static_Object *get_target_obj();
};

RGE_Static_Object * RGE_Static_Object::get_target_obj() {
    return 0;
}
