#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle360(int param_1);

public:
    float sine360[360];

    float sin360(int param_1);
};
#endif

float TRIGONOMETRY::sin360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->sine360[index];
}
