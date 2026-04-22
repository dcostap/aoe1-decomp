class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup);
    int setup(RGE_Master_Static_Object* object);
};

RGE_Master_Static_Object::RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup) {
    if (do_setup != 0) {
        setup(object);
    }
}
