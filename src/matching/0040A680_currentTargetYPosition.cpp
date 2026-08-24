#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[148];
    float currentTargetYPosition_;

    float currentTargetYPosition() const;
};
#endif

float BaseObject::currentTargetYPosition() const {
    return this->currentTargetYPosition_;
}
