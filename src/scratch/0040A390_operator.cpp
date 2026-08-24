#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[0x18];
    int gameIDValue;
};
#endif

int operator!=(const BaseObject& lhs, const BaseObject& rhs) {
    return lhs.gameIDValue != rhs.gameIDValue;
}
