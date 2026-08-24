#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[104];
    float xSize_;

    void setXSize(float);
};
#endif

void BaseObject::setXSize(float val) {
    this->xSize_ = val;
}
