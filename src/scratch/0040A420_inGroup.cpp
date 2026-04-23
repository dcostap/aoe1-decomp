class BaseObject {
public:
    char gap_00[0x0C];
    int numberGroupsValue;
    int* groupIDValue;

    int inGroup(int group) const;
};

int BaseObject::inGroup(int group) const {
    int count = this->numberGroupsValue;
    int i = 0;
    int* ids;

    if (count <= 0) {
        return 0;
    }
    ids = this->groupIDValue;
    do {
        if (*ids == group) {
            return 1;
        }
        i++;
        ids++;
    } while (i < count);
    return 0;
}
