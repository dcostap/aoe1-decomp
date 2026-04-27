// Attempt 4: i declared but born late
class BaseObject {
public:
    void* vftable;
    char gap_04[0x08];
    int numberGroupsValue;
    int* groupIDValue;

    int inGroup(int group_id) const;
};

int BaseObject::inGroup(int group_id) const {
    int i;
    i = 0;
    if (numberGroupsValue <= 0) {
        return 0;
    }
    int* p = groupIDValue;
    do {
        if (*p == group_id) {
            return 1;
        }
        i++;
        p++;
    } while (i < numberGroupsValue);
    return 0;
}
