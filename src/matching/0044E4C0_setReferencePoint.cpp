class InfluenceMap {
public:
    char gap_0[0xC];
    int field_C;
    int field_10;
    void setReferencePoint(int a, int b);
};

void InfluenceMap::setReferencePoint(int a, int b) {
    this->field_C = a;
    this->field_10 = b;
}
