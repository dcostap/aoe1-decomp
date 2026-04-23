class TRIGONOMETRY {
public:
    int RestrictAngle(int param_1);
    float sines[4096];

    float sine(int param_1);
};

float TRIGONOMETRY::sine(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->sines[index];
}
