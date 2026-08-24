#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[92];
    float xPosition_;

    void setXPosition(float);
};
#endif

void BaseObject::setXPosition(float val) {
    this->xPosition_ = val;
}
