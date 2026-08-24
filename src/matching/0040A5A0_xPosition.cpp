#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[92];
    float xPosition_;

    float xPosition() const;
};
#endif

float BaseObject::xPosition() const {
    return this->xPosition_;
}
