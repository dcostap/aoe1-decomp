#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[108];
    float ySize_;

    void setYSize(float);
};
#endif

void BaseObject::setYSize(float val) {
    this->ySize_ = val;
}
