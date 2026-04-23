class TRIGONOMETRY {
public:
    int RestrictAngle360(int param_1);
    float atane360[360];

    float atan360(int param_1);
};

float TRIGONOMETRY::atan360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->atane360[index];
}
