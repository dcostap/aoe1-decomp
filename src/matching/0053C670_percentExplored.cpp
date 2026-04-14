class Exploration {
public:
    char gap_0[0x1C];
    int explored;
    int total;
    float percentExplored();
};

float Exploration::percentExplored() {
    return (float)this->explored / (float)this->total;
}
