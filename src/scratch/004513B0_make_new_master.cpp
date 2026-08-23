// attempt log:
// first pass: direct new-expression for the EH-framed factory helper
// target shape: return new RGE_Master_Doppleganger_Object(this, 1); with 0xBC allocation size

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char pad_4[0xB8 - 0x4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char pad_B8[0xBC - 0xB8];
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* source, int do_setup);
};

class RGE_Master_Doppleganger_Object_Factory {
public:
    RGE_Master_Static_Object* make_new_master(void);
};

RGE_Master_Static_Object* RGE_Master_Doppleganger_Object_Factory::make_new_master(void) {
    return new RGE_Master_Doppleganger_Object((RGE_Master_Doppleganger_Object*)this, 1);
}
