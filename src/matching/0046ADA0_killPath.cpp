#ifndef PATH_TU_CONTEXT
class Path {
public:
    char gap_0[0x2C];
    int field_2C;
    int field_30;
    void killPath();
};
#endif

#ifdef PATH_TU_CONTEXT
void Path::killPath() {
    this->currentSizeValue = 0;
    this->currentWaypointValue = 0;
}
#else
void Path::killPath() {
    this->field_2C = 0;
    this->field_30 = 0;
}
#endif
