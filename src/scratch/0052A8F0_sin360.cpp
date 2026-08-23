class TRIGONOMETRY {
public:
    int RestrictAngle360(int param_1);
    float sine360[360];

    float sin360(int param_1);
};

float TRIGONOMETRY::sin360(int param_1) {
    int index = this->RestrictAngle360(param_1);
    return this->sine360[index];
}
