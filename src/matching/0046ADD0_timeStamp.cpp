#ifndef PATH_TU_CONTEXT
class Path {
public:
    int field_0;
    int timeStamp();
};
#endif

#ifdef PATH_TU_CONTEXT
unsigned long Path::timeStamp() const { return this->timeStampValue; }
#else
int Path::timeStamp() { return this->field_0; }
#endif
