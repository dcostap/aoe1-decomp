#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle(int param_1);

public:
    float sines[4096];

    float sine(int param_1);
};
#endif

float TRIGONOMETRY::sine(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->sines[index];
}
