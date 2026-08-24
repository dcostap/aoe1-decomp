#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[132];
    int currentTask_;

    int currentTask() const;
};
#endif

int BaseObject::currentTask() const {
    return this->currentTask_;
}
