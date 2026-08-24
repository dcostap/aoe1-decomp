#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[136];
    int currentTarget_;

    int currentTarget() const;
};
#endif

int BaseObject::currentTarget() const {
    return this->currentTarget_;
}
