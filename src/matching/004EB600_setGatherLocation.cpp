class TacticalAIGroup {
public:
    char gap_0[0x19C];
    int field_19C;
    int field_1A0;
    int field_1A4;
    void setGatherLocation(int a, int b, int c);
};

void TacticalAIGroup::setGatherLocation(int a, int b, int c) {
    this->field_19C = a;
    this->field_1A0 = b;
    this->field_1A4 = c;
}
