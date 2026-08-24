#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x28];
    int field_2C;
    int numberOfWaypoints();
};
#endif

#ifdef PATH_TU_CONTEXT
int Path::numberOfWaypoints() const { return this->currentSizeValue; }
#else
int Path::numberOfWaypoints() { return this->field_2C; }
#endif
