#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle360(int param_1);

public:
    float cose360[360];

    float cos360(int param_1);
};
#endif

float TRIGONOMETRY::cos360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->cose360[index];
}
