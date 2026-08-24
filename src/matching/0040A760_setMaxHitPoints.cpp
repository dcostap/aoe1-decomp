#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[124];
    int maxHitPoints_;

    void setMaxHitPoints(int);
};
#endif

void BaseObject::setMaxHitPoints(int val) {
    this->maxHitPoints_ = val;
}
