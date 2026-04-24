// tried the direct local-return shape and then the constructor-return shape; VC5 flipped between a 64-byte and a 48-byte basin
// the remaining gap is the exact UDT-return lowering / hidden return-storage shape, not the arithmetic
// leaving in scratch as a paused near-match

class XYZ {
public:
    int xValue;
    int yValue;
    int zValue;

    XYZ();
    XYZ(int x, int y, int z);
    XYZ operator+(const XYZ& other) const;
};

XYZ XYZ::operator+(const XYZ& other) const {
    XYZ newP;
    int local_4;
    newP.xValue = this->xValue + other.xValue;
    newP.yValue = this->yValue + other.yValue;
    newP.zValue = this->zValue + other.zValue;
    return newP;
}
