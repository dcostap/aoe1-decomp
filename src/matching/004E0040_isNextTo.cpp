#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class XYPoint {
public:
    int x;
    int y;
};

class TribeInformationAIModule {
public:
    int isNextTo(XYPoint* p1, XYPoint* p2, int mode);
};
#endif

#endif
int TribeInformationAIModule::isNextTo(XYPoint* p1, XYPoint* p2, int mode) {
    int dx = p2->x - p1->x;
    int dy = p2->y - p1->y;
    int dist = dx * dx + dy * dy;
    if (mode == 0) {
        if (dist > 1) {
            return 0;
        }
        goto check_mode1;
    }
check_mode1:
    if (mode == 1) {
        if (dist > 2) {
            return 0;
        }
    }
    return 1;
}
