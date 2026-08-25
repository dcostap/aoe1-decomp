#ifndef TAITACMD_SHARED_CONTEXT
class TacticalAIGroup {
public:
    char gap_0[0x18C];
    int field_18C;
    int field_190;
    int field_194;
    void setTargetLocation(int a, int b, int c);
};
#endif

void TacticalAIGroup::setTargetLocation(int a, int b, int c) {
    this->field_18C = a;
    this->field_190 = b;
    this->field_194 = c;
}
