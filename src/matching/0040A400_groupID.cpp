#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[0x08];
    int numberGroupsValue;
    int* groupIDValue;

    int groupID(int index) const;
};
#endif

int BaseObject::groupID(int index) const {
    if (groupIDValue != 0 && index >= 0 && index < numberGroupsValue) {
        return groupIDValue[index];
    }
    return -1;
}
