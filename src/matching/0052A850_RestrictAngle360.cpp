#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle360(int param_1);
};
#endif

int TRIGONOMETRY::RestrictAngle360(int param_1) {
    int value = param_1 % 0x168;
    if (value < 0) {
        value = -value;
    }
    return value;
}
