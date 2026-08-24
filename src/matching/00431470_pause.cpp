#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Combat_Object_State {
public:
    unsigned char gap_00[0x18];
    int value_18;
};

class RGE_Combat_Object {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual int vf38(int value);

    unsigned char gap_04[0x4];
    RGE_Combat_Object_State* state;

    virtual int pause();
};
#endif

int RGE_Combat_Object::pause() {
    vf38(state->value_18);
    return 1;
}
