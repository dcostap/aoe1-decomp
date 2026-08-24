#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[116];
    int hitPoints_;

    void setHitPoints(int);
};
#endif

void BaseObject::setHitPoints(int val) {
    this->hitPoints_ = val;
}
