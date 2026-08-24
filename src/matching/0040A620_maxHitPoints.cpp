#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[124];
    int maxHitPoints_;

    int maxHitPoints() const;
};
#endif

int BaseObject::maxHitPoints() const {
    return this->maxHitPoints_;
}
