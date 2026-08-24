#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    char gap_0[0xC];
    int xReferencePointValue;
    int yReferencePointValue;
    void setReferencePoint(int a, int b);
};
#endif

void InfluenceMap::setReferencePoint(int a, int b) {
    this->xReferencePointValue = a;
    this->yReferencePointValue = b;
}
