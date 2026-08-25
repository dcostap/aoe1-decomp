#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_0[0x170];
    int field_170;
    int field_174;
    int field_178;
    void setLocation(int a, int b, int c);
};
#endif

void TacticalAIGroup::setLocation(int a, int b, int c) {
    this->field_170 = a;
    this->field_174 = b;
    this->field_178 = c;
}
