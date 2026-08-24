#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[132];
    int currentTask_;

    void setCurrentTask(int);
};
#endif

void BaseObject::setCurrentTask(int val) {
    this->currentTask_ = val;
}
