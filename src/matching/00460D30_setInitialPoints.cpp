struct XYPoint {
    int x;
    int y;
};

class RGE_Moving_Object {
public:
    char gap_00[0x158];
    XYPoint minInitialPointValue;
    XYPoint maxInitialPointValue;

    void setInitialPoints(XYPoint& minPoint, XYPoint& maxPoint);
};

void RGE_Moving_Object::setInitialPoints(XYPoint& minPoint, XYPoint& maxPoint) {
    this->minInitialPointValue.x = minPoint.x;
    this->minInitialPointValue.y = minPoint.y;
    this->maxInitialPointValue.x = maxPoint.x;
    this->maxInitialPointValue.y = maxPoint.y;
}
