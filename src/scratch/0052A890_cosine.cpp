#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle(int param_1);

public:
    float cose[4096];

    float cosine(int param_1);
};
#endif

float TRIGONOMETRY::cosine(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->cose[index];
}
