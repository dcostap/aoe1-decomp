#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[120];
    int minHitPoints_;

    void incrementMinHitPoints(int);
};
#endif

void BaseObject::incrementMinHitPoints(int val) {
    this->minHitPoints_ += val;
}
