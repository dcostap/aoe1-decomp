#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[100];
    float zPosition_;

    void setZPosition(float);
};
#endif

void BaseObject::setZPosition(float val) {
    this->zPosition_ = val;
}
