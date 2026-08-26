#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x24];
    int field_28;
    const int maxNumberOfWaypoints();
};
#endif

#ifdef PATH_TU_CONTEXT
const int Path::maxNumberOfWaypoints() const { return this->maxSizeValue; }
#else
const int Path::maxNumberOfWaypoints() { return this->field_28; }
#endif
