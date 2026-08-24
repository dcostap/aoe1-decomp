#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[8];
    int numberGroups_;

    int numberGroups() const;
};
#endif

int BaseObject::numberGroups() const {
    return this->numberGroups_;
}
