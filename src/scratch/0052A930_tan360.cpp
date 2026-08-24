#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
private:
    int RestrictAngle360(int param_1);

public:
    float tane360[360];

    float tan360(int param_1);
};
#endif

float TRIGONOMETRY::tan360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->tane360[index];
}
