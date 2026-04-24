// From taitacmd.cpp

class TacticalAIGroup {
public:
    char gap_00[0x170];
    float field_170;
    float field_174;
    float field_178;
    char gap_17C[0x20];
    float field_19C;
    float field_1A0;
    float field_1A4;
    char gap_1A8[0x4];
    float field_1AC;
    float field_1B0;
    float field_1B4;

    void setAllLocations(float p1, float p2, float p3);
};

void TacticalAIGroup::setAllLocations(float p1, float p2, float p3) {
    this->field_170 = p1;
    this->field_174 = p2;
    this->field_178 = p3;
    this->field_19C = p1;
    this->field_1A0 = p2;
    this->field_1A4 = p3;
    this->field_1AC = p1;
    this->field_1B0 = p2;
    this->field_1B4 = p3;
}
