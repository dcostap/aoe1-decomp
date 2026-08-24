#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[112];
    float zSize_;

    void setZSize(float);
};
#endif

void BaseObject::setZSize(float val) {
    this->zSize_ = val;
}
