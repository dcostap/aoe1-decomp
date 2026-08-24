#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[140];
    int currentTargetType_;

    int currentTargetType() const;
};
#endif

int BaseObject::currentTargetType() const {
    return this->currentTargetType_;
}
