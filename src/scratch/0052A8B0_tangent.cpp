class TRIGONOMETRY {
public:
    int RestrictAngle(int param_1);
    float tane[4096];

    float tangent(int param_1);
};

float TRIGONOMETRY::tangent(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->tane[index];
}
