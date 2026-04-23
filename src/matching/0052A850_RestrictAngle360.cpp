class TRIGONOMETRY {
public:
    int RestrictAngle360(int param_1);
};

int TRIGONOMETRY::RestrictAngle360(int param_1) {
    int value = param_1 % 0x168;
    if (value < 0) {
        value = -value;
    }
    return value;
}
