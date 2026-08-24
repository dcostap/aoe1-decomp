#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[20];
    int typeID_;

    int typeID() const;
};
#endif

int BaseObject::typeID() const {
    return this->typeID_;
}
