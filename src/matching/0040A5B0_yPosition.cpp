#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[96];
    float yPosition_;

    float yPosition() const;
};
#endif

float BaseObject::yPosition() const {
    return this->yPosition_;
}
