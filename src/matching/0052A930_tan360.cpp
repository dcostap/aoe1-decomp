class TRIGONOMETRY {
public:
    int RestrictAngle360(int param_1);
    float tane360[360];

    float tan360(int param_1);
};

float TRIGONOMETRY::tan360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->tane360[index];
}
