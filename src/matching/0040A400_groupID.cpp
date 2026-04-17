class BaseObject {
public:
    void* vftable;
    char gap_04[0x08];
    int numberGroupsValue;
    int* groupIDValue;

    int groupID(int index) const;
};

int BaseObject::groupID(int index) const {
    if (groupIDValue != 0 && index >= 0 && index < numberGroupsValue) {
        return groupIDValue[index];
    }
    return -1;
}
