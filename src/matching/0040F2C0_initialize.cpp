class AIPlayGroup {
public:
    unsigned char minValue[6];
    unsigned char maxValue[6];

    void initialize(void);
};

void AIPlayGroup::initialize(void) {
    for (int i = 0; i < 6; ++i) {
        this->minValue[i] = 0;
        this->maxValue[i] = 0xFE;
    }
}
