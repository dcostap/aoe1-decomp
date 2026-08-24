#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[108];
    float ySize_;

    float ySize() const;
};
#endif

float BaseObject::ySize() const {
    return this->ySize_;
}
