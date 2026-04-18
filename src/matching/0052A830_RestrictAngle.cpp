class SomeClass {
public:
    int RestrictAngle(int angle);
};
int SomeClass::RestrictAngle(int angle) {
    int result = angle % 4096;
    if (result < 0) result = -result;
    return result;
}
