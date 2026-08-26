#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle(int param_1);
};
#endif

int TRIGONOMETRY::RestrictAngle(int param_1) {
    int value = param_1 % 0x1000;
    return value < 0 ? -value : value;
}
