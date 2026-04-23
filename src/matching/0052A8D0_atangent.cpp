class TRIGONOMETRY {
public:
    int RestrictAngle(int param_1);
    float atane[4096];

    float atangent(int param_1);
};

float TRIGONOMETRY::atangent(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->atane[index];
}
