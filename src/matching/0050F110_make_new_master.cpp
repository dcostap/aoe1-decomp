// first pass: direct new-expression for the EH-framed factory helper
// if this is sticky, the only real follow-up is whether /GX is required to keep the ctor/new basin
#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    char pad_04[0xB8 - 0x4];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char pad_B8[0x148 - 0xB8];
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char pad_148[0x164 - 0x148];
    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* source, int do_setup);
    RGE_Master_Static_Object* make_new_master(void);
};
#endif

RGE_Master_Static_Object* TRIBE_Master_Combat_Object::make_new_master(void) {
    return new TRIBE_Master_Combat_Object(this, 1);
}
