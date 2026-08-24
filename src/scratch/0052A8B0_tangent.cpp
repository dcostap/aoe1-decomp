#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle(int param_1);

public:
    float tane[4096];

    float tangent(int param_1);
};
#endif

float TRIGONOMETRY::tangent(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->tane[index];
}
