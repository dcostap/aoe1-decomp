// attempt 1: direct four-way axis/sign facet selection from the XY delta pair
// exact match landed with the axis-first compare order and the algebraic branchless return forms for the 8-way facet code

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class XYPoint {
public:
    int x;
    int y;
};

class TribeInformationAIModule {
public:
    int facetTo(XYPoint& from, XYPoint& to);
};
#endif

#endif
int TribeInformationAIModule::facetTo(XYPoint& from, XYPoint& to) {
    int dx;
    int dy;

    dx = to.x - from.x;
    dy = to.y - from.y;

    if (dx == 0) {
        if (dy < 0) {
            return 1;
        }
        return 5;
    }
    if (dy == 0) {
        return ((dx >= 0) - 1 & 4) + 3;
    }
    if (dx < 0) {
        if (dy < 0) {
            return 0;
        }
        return 6;
    }
    if (dy < 0) {
        return 2;
    }
    return 4;
}
