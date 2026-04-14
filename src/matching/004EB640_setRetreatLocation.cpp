class TacticalAIGroup {
public:
    char gap_0[0x1AC];
    int field_1AC;
    int field_1B0;
    int field_1B4;
    void setRetreatLocation(int a, int b, int c);
};

void TacticalAIGroup::setRetreatLocation(int a, int b, int c) {
    this->field_1AC = a;
    this->field_1B0 = b;
    this->field_1B4 = c;
}
