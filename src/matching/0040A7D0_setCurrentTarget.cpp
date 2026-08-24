#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[136];
    int currentTarget_;

    void setCurrentTarget(int);
};
#endif

void BaseObject::setCurrentTarget(int val) {
    this->currentTarget_ = val;
}
