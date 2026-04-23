class TRIGONOMETRY {
public:
    int RestrictAngle(int param_1);
    float cose[4096];

    float cosine(int param_1);
};

float TRIGONOMETRY::cosine(int param_1) {
    int index = this->RestrictAngle(param_1);
    return this->cose[index];
}
