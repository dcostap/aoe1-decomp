#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[128];
    int busy_;

    int busy() const;
};
#endif

int BaseObject::busy() const {
    return this->busy_;
}
