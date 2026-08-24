#ifndef PATH_TU_CONTEXT
class Path {
public:
    virtual ~Path();
    char field_4[1];
    char* start();
};
#endif

#ifdef PATH_TU_CONTEXT
const Waypoint& Path::start() const { return this->startValue; }
#else
char* Path::start() { return this->field_4; }
#endif
