#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char gap_0[0x10];
    char field_14[1];
    char* goal();
};
#endif

#ifdef PATH_TU_CONTEXT
const Waypoint& Path::goal() const { return this->goalValue; }
#else
char* Path::goal() { return this->field_14; }
#endif
