#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[116];
    int hitPoints_;

    int hitPoints() const;
};
#endif

int BaseObject::hitPoints() const {
    return this->hitPoints_;
}
