#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[100];
    float zPosition_;

    float zPosition() const;
};
#endif

float BaseObject::zPosition() const {
    return this->zPosition_;
}
