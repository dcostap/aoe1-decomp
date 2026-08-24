#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[140];
    int currentTargetType_;

    void setCurrentTargetType(int);
};
#endif

void BaseObject::setCurrentTargetType(int val) {
    this->currentTargetType_ = val;
}
