#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[0x18];
    int gameID_;

    const int & gameID() const;
};
#endif

const int & BaseObject::gameID() const {
    return this->gameID_;
}
