#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[120];
    int minHitPoints_;

    int minHitPoints() const;
};
#endif

int BaseObject::minHitPoints() const {
    return this->minHitPoints_;
}
