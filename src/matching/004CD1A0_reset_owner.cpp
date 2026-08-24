#ifndef AOE1_TACT_ART_TU_CONTEXT
class TRIBE_Action_Artifact {
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
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C(int val);
    void reset_owner();
};
#endif

// BINARY NOTE: tact_art.cpp lines 263-265 dispatch state 100 through vslot 0x5C.
void TRIBE_Action_Artifact::reset_owner() {
#ifdef AOE1_TACT_ART_TU_CONTEXT
    this->set_state(100);
#else
    this->vf5C(100);
#endif
}
