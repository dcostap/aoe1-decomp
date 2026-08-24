#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[116];
    int hitPoints_;

    void decrementHitPoints(int);
};
#endif

void BaseObject::decrementHitPoints(int val) {
    this->hitPoints_ -= val;
}
