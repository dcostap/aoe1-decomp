#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle(int param_1);

public:
    float atane[4096];

    float atangent(int param_1);
};
#endif

float TRIGONOMETRY::atangent(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->atane[index];
}
