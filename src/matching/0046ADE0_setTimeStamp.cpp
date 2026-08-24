#ifndef PATH_TU_CONTEXT
class Path {
public:
    int field_0;
    void setTimeStamp(int v);
};
#endif

#ifdef PATH_TU_CONTEXT
void Path::setTimeStamp(unsigned long v) { this->timeStampValue = v; }
#else
void Path::setTimeStamp(int v) { this->field_0 = v; }
#endif
