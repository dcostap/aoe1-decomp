#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual void vf00(void) const;
    virtual void vf04(void) const;
    virtual void vf08(void) const;
    virtual void vf0C(void) const;
    virtual void vf10(void) const;
    virtual void vf14(void) const;
    virtual void vf18(void) const;
    virtual void vf1C(void) const;
    virtual void vf20(void) const;
    virtual void vf24(void) const;
    virtual void vf28(void) const;
    virtual void vf2C(void) const;
    virtual void vf30(void) const;
    virtual void vf34(void) const;
    virtual void vf38(void) const;
    virtual void vf3C(void) const;
    virtual void vf40(void) const;
    virtual void vf44(void) const;
    virtual void vf48(void) const;
    virtual void vf4C(void) const;
    virtual void vf50(void) const;
    virtual void vf54(void) const;
    virtual void vf58(void) const;
    virtual void vf5C(void) const;
    virtual void vf60(void) const;
    virtual void vf64(void) const;
    virtual void vf68(void) const;
    virtual void vf6C(void) const;
    virtual void vf70(void) const;
    virtual void vf74(void) const;
    virtual void vf78(void) const;
    virtual void vf7C(void) const;
    virtual void vf80(void) const;
    virtual void vf84(void) const;
    virtual void vf88(void) const;
    virtual void vf8C(void) const;
    virtual void vf90(void) const;
    virtual void vf94(void) const;
    virtual void vf98(void) const;
    virtual void vf9C(void) const;
    virtual void vfA0(void) const;
    virtual void vfA4(void) const;
    virtual void vfA8(void) const;
    virtual void vfAC(void) const;
    virtual void vfB0(void) const;
    virtual void vfB4(void) const;
    virtual void vfB8(void) const;
    virtual void vfBC(void) const;
    virtual void vfC0(void) const;
    virtual void vfC4(void) const;
    virtual void vfC8(void) const;
    virtual void vfCC(void) const;
    virtual void vfD0(void) const;
    virtual void vfD4(void) const;
    virtual void vfD8(void) const;
    virtual void vfDC(void) const;
    virtual void vfE0(void) const;
    virtual void vfE4(void) const;
    virtual void vfE8(void) const;
    virtual void vfEC(void) const;
    virtual void vfF0(void) const;
    virtual void vfF4(void) const;
    virtual void vfF8(void) const;
    virtual void vfFC(void) const;
    virtual void vf100(void) const;
    virtual void vf104(void) const;
    virtual void vf108(void) const;
    virtual void vf10C(void) const;
    virtual void vf110(void) const;
    virtual void vf114(void) const;
    virtual void vf118(void) const;
    virtual void vf11C(void) const;
    virtual void vf120(void) const;
    virtual void vf124(void) const;
    virtual void vf128(void) const;
    virtual void vf12C(void) const;
    virtual void vf130(void) const;
    virtual int movement_state(void) const;

    char gap_04[0x151];
    unsigned char waitingToMoveValue;

    virtual unsigned char waitingToMove(void) const;
};
#endif

unsigned char RGE_Moving_Object::waitingToMove(void) const {
    unsigned int state = (unsigned char)this->movement_state();

    if ((state == 6) || (state == 7)) {
        return 0;
    }
    return this->waitingToMoveValue;
}
