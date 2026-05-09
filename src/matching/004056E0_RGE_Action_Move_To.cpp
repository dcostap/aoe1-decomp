// 004056E0 RGE_Action_Move_To::~RGE_Action_Move_To
// FLAGS: /GX
// Attempt log:
// 1. Existing wide virtual surface gets exact +0x1C0/+0x1EC virtual offsets, but VC5 reorders vptr store after object load/EH state and routes base dtor through local thunk basin.
// 2. Declared base destructor only + volatile vtable_ptr: no improvement; vptr store still after object load/state.
// 3. Natural virtual destructor surface, let VC5 emit derived vptr restore.

class RGE_Action_Object {
public:
    virtual void vf00(void); virtual void vf01(void); virtual void vf02(void); virtual void vf03(void);
    virtual void vf04(void); virtual void vf05(void); virtual void vf06(void); virtual void vf07(void);
    virtual void vf08(void); virtual void vf09(void); virtual void vf0A(void); virtual void vf0B(void);
    virtual void vf0C(void); virtual void vf0D(void); virtual void vf0E(void); virtual void vf0F(void);
    virtual void vf10(void); virtual void vf11(void); virtual void vf12(void); virtual void vf13(void);
    virtual void vf14(void); virtual void vf15(void); virtual void vf16(void); virtual void vf17(void);
    virtual void vf18(void); virtual void vf19(void); virtual void vf1A(void); virtual void vf1B(void);
    virtual void vf1C(void); virtual void vf1D(void); virtual void vf1E(void); virtual void vf1F(void);
    virtual void vf20(void); virtual void vf21(void); virtual void vf22(void); virtual void vf23(void);
    virtual void vf24(void); virtual void vf25(void); virtual void vf26(void); virtual void vf27(void);
    virtual void vf28(void); virtual void vf29(void); virtual void vf2A(void); virtual void vf2B(void);
    virtual void vf2C(void); virtual void vf2D(void); virtual void vf2E(void); virtual void vf2F(void);
    virtual void vf30(void); virtual void vf31(void); virtual void vf32(void); virtual void vf33(void);
    virtual void vf34(void); virtual void vf35(void); virtual void vf36(void); virtual void vf37(void);
    virtual void vf38(void); virtual void vf39(void); virtual void vf3A(void); virtual void vf3B(void);
    virtual void vf3C(void); virtual void vf3D(void); virtual void vf3E(void); virtual void vf3F(void);
    virtual void vf40(void); virtual void vf41(void); virtual void vf42(void); virtual void vf43(void);
    virtual void vf44(void); virtual void vf45(void); virtual void vf46(void); virtual void vf47(void);
    virtual void vf48(void); virtual void vf49(void); virtual void vf4A(void); virtual void vf4B(void);
    virtual void vf4C(void); virtual void vf4D(void); virtual void vf4E(void); virtual void vf4F(void);
    virtual void vf50(void); virtual void vf51(void); virtual void vf52(void); virtual void vf53(void);
    virtual void vf54(void); virtual void vf55(void); virtual void vf56(void); virtual void vf57(void);
    virtual void vf58(void); virtual void vf59(void); virtual void vf5A(void); virtual void vf5B(void);
    virtual void vf5C(void); virtual void vf5D(void); virtual void vf5E(void); virtual void vf5F(void);
    virtual void vf60(void); virtual void vf61(void); virtual void vf62(void); virtual void vf63(void);
    virtual void vf64(void); virtual void vf65(void); virtual void vf66(void); virtual void vf67(void);
    virtual void vf68(void); virtual void vf69(void); virtual void vf6A(void); virtual void vf6B(void);
    virtual void vf6C(void); virtual void vf6D(void); virtual void vf6E(void); virtual void vf6F(void);
    virtual void vf70(int value); virtual void vf71(void); virtual void vf72(void); virtual void vf73(void);
    virtual void vf74(void); virtual void vf75(void); virtual void vf76(void); virtual void vf77(void);
    virtual void vf78(void); virtual void vf79(void); virtual void vf7A(void); virtual void vf7B(void);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    char gap_0C[0x44 - 0x0C];
};

class RGE_Action_Move_To : public RGE_Action {
public:
    virtual ~RGE_Action_Move_To();
};

RGE_Action_Move_To::~RGE_Action_Move_To() {
    this->obj->vf70(0);
    this->obj->vf7B();
}
