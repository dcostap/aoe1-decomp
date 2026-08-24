#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[16];
    int categoryID_;

    int categoryID() const;
};
#endif

int BaseObject::categoryID() const {
    return this->categoryID_;
}
