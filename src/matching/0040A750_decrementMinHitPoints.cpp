#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[120];
    int minHitPoints_;

    void decrementMinHitPoints(int);
};
#endif

void BaseObject::decrementMinHitPoints(int val) {
    this->minHitPoints_ -= val;
}
