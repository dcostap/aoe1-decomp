#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[144];
    float currentTargetXPosition_;

    float currentTargetXPosition() const;
};
#endif

float BaseObject::currentTargetXPosition() const {
    return this->currentTargetXPosition_;
}
