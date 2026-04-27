// attempt 2: 101 vs 101, fild stack offsets wrong ([esp+10]/[esp+14] vs [esp+C]/[esp+10])
// attempt 1: same issue with member calls
// PAUSED: VC5 loads float params from different stack positions than original
// The original loads from [esp+C] and [esp+10], but VC5 loads from [esp+10] and [esp+14]
// This is a stack-layout/codegen basin issue with FPU + member call interaction

struct RGE_Static_Object;

class UnitAIModule {
public:
    void* vftable;
    RGE_Static_Object* objectValue;
    char gap_8[0x28];
    int currentActionValue;

    int exploreAndDestroy(int param_1, int param_2, int param_3);
};

class RGE_Static_Object_Base {
public:
    virtual void vf00() = 0; virtual void vf01() = 0; virtual void vf02() = 0; virtual void vf03() = 0;
    virtual void vf04() = 0; virtual void vf05() = 0; virtual void vf06() = 0; virtual void vf07() = 0;
    virtual void vf08() = 0; virtual void vf09() = 0; virtual void vf10() = 0; virtual void vf11() = 0;
    virtual void vf12() = 0; virtual void vf13() = 0; virtual void vf14() = 0; virtual void vf15() = 0;
    virtual void vf16() = 0; virtual void vf17() = 0; virtual void vf18() = 0; virtual void vf19() = 0;
    virtual void vf20() = 0; virtual void vf21() = 0; virtual void vf22() = 0; virtual void vf23() = 0;
    virtual void vf24() = 0; virtual void vf25() = 0; virtual void vf26() = 0; virtual void vf27() = 0;
    virtual void vf28() = 0; virtual void vf29() = 0; virtual void vf30() = 0; virtual void vf31() = 0;
    virtual void vf32() = 0; virtual void vf33() = 0; virtual void vf34() = 0; virtual void vf35() = 0;
    virtual void vf36() = 0; virtual void vf37() = 0; virtual void vf38() = 0; virtual void vf39() = 0;
    virtual void vf40() = 0; virtual void vf41() = 0; virtual void vf42() = 0; virtual void vf43() = 0;
    virtual void vf44() = 0; virtual void vf45() = 0; virtual void vf46() = 0; virtual void vf47() = 0;
    virtual void vf48() = 0; virtual void vf49() = 0; virtual void vf50() = 0; virtual void vf51() = 0;
    virtual void vf52() = 0; virtual void vf53() = 0; virtual void vf54() = 0; virtual void vf55() = 0;
    virtual void vf56() = 0; virtual void vf57() = 0; virtual void vf58() = 0; virtual void vf59() = 0;
    virtual void vf60() = 0; virtual void vf61() = 0; virtual void vf62() = 0; virtual void vf63() = 0;
    virtual void vf64() = 0; virtual void vf65() = 0; virtual void vf66() = 0; virtual void vf67() = 0;
    virtual void vf68() = 0; virtual void vf69() = 0; virtual void vf70() = 0; virtual void vf71() = 0;
    virtual void vf72() = 0; virtual void vf73() = 0; virtual void vf74() = 0; virtual void vf75() = 0;
    virtual void vf76() = 0; virtual void vf77() = 0; virtual void vf78() = 0; virtual void vf79() = 0;
    virtual void vf80() = 0; virtual void vf81() = 0; virtual void vf82() = 0; virtual void vf83() = 0;
    virtual void vf84() = 0; virtual void vf85() = 0; virtual void vf86() = 0; virtual void vf87() = 0;
    virtual void vf88() = 0; virtual void vf89() = 0; virtual void vf90() = 0; virtual void vf91() = 0;
    virtual void vf92() = 0; virtual void vf93() = 0; virtual void vf94() = 0;
};

class RGE_Static_Object : public RGE_Static_Object_Base {
public:
    virtual int explore(int param_1, int param_2, int param_3) = 0;
};

void setCurrentAction(UnitAIModule* self, int action);
void setCurrentTarget(UnitAIModule* self, int target, float x, float y, float z);

int UnitAIModule::exploreAndDestroy(int param_1, int param_2, int param_3) {
    if ((param_3 != 0) || (this->currentActionValue == -1)) {
        if (this->objectValue->explore(param_1, param_2, param_3) == 1) {
            setCurrentAction(this, 0x26F);
            setCurrentTarget(this, -1, (float)param_2, (float)param_3, 1.0f);
            return 1;
        }
    }
    return 0;
}
