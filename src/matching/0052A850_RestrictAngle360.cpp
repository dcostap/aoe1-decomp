class SomeClass {
public:
    int RestrictAngle360(int angle);
};
int SomeClass::RestrictAngle360(int angle) {
    int result = angle % 360;
    if (result < 0) result = -result;
    return result;
}
