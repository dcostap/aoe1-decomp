// attempt 1: direct new-expression for the EH-framed factory helper
// result: the direct form landed 96 bytes; the original likely wants the explicit ctor/new basin with the base object surface
// attempt 2: keep the class size at 0xB8 and retry the natural new-expression

#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char pad_04[0xB8 - 0x4];

    RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup);
    virtual RGE_Master_Static_Object* make_new_master(void);
};
#endif

RGE_Master_Static_Object* RGE_Master_Static_Object::make_new_master(void) {
    return new RGE_Master_Static_Object(this, 1);
}
