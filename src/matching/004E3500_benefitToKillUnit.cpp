struct ResultObj {
    char gap_0[0x08];
    void* field_8_ptr;  // 0x08
    void* field_C_ptr;  // 0x0C
};

struct LookupHelper {
    ResultObj* lookup(int unitId);
};

struct VTableBase {
    virtual void vf00() {}
    virtual void vf04() {}
    virtual void vf08() {}
    virtual void vf0C() {}
    virtual void vf10() {}
    virtual void vf14() {}
    virtual void vf18() {}
    virtual void vf1C() {}
    virtual void vf20() {}
    virtual void vf24() {}
    virtual void vf28() {}
    virtual void vf2C() {}
    virtual void vf30() {}
    virtual void vf34() {}
    virtual void vf38() {}
    virtual void vf3C() {}
    virtual void vf40() {}
    virtual void vf44() {}
    virtual void vf48() {}
    virtual void vf4C() {}
    virtual void vf50() {}
    virtual void vf54() {}
    virtual int benefit(int val) { return 0; }
};

struct TribeTacticalAIModule {
    char gap_0[0x100];
    LookupHelper* mainDecisionAI;  // 0x100
};

int __fastcall benefitToKillUnit(TribeTacticalAIModule* self, int, int unitId) {
    ResultObj* result = self->mainDecisionAI->lookup(unitId);
    if (!result)
        return -1;
    short val = *(short*)((char*)result->field_8_ptr + 0x10);
    VTableBase* obj = (VTableBase*)result->field_C_ptr;
    return obj->benefit((int)val);
}
