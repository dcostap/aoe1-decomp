#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle360(int param_1);

public:
    float atane360[360];

    float atan360(int param_1);
};
#endif

float TRIGONOMETRY::atan360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->atane360[index];
}
