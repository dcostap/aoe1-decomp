// attempt 1: natural ctor body with the base ctor call, vtable store, and optional setup helper
// result: default flags were too small; /GX is justified for this ctor/EH basin
// attempt 2: keep the body minimal and exact, with the byte+4 tree flag only on the setup path

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup);
    int setup(RGE_Master_Static_Object* object);
};

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    char field_04;

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2);
    int setup(TRIBE_Master_Tree_Object* other);
};

TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2)
    : RGE_Master_Static_Object((RGE_Master_Static_Object*)param_1, 0) {
    *(void**)this = (void*)0x576790;
    if (param_2 != 0) {
        setup(param_1);
        this->field_04 = 0x5A;
    }
}
