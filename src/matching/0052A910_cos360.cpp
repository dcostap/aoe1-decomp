class TRIGONOMETRY {
public:
    int RestrictAngle360(int param_1);
    float cose360[360];

    float cos360(int param_1);
};

float TRIGONOMETRY::cos360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->cose360[index];
}
