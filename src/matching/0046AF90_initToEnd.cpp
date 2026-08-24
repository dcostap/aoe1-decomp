#ifndef PATH_TU_CONTEXT
class Path {
public:
    char gap_0[0x2C];
    int field_2C;
    int field_30;
    void initToEnd();
};
#endif

#ifdef PATH_TU_CONTEXT
void Path::initToEnd() {
    this->currentWaypointValue = this->currentSizeValue - 1;
}
#else
void Path::initToEnd() {
    this->field_30 = this->field_2C - 1;
}
#endif
