#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle(int param_1);
};
#endif

int TRIGONOMETRY::RestrictAngle(int param_1) {
    int sign = param_1 >> 31;
    int value = ((param_1 ^ sign) - sign) & 0xFFF;
    value = (value ^ sign) - sign;
    if (value < 0) {
        value = -value;
    }
    return value;
}
