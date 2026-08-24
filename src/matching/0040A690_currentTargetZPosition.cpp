#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[152];
    float currentTargetZPosition_;

    float currentTargetZPosition() const;
};
#endif

float BaseObject::currentTargetZPosition() const {
    return this->currentTargetZPosition_;
}
