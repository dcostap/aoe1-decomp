#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x28];
    int field_2C;
    const int numberOfWaypoints();
};
#endif

#ifdef PATH_TU_CONTEXT
const int Path::numberOfWaypoints() const { return this->currentSizeValue; }
#else
const int Path::numberOfWaypoints() { return this->field_2C; }
#endif
