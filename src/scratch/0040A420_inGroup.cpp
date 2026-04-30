// 0040A420 BaseObject::inGroup
// PDB: aibobj.cpp:212-217, 50 bytes
// __thiscall, ret 4
// FLAGS: default
//
// Probe 15: minimal matching approach

class BaseObject {
public:
    char pad_00[0x0C];
    int numberGroupsValue;   // +0x0C
    int* groupIDValue;       // +0x10

    int inGroup(int groupId) const;
};

int BaseObject::inGroup(int groupId) const {
    int count = this->numberGroupsValue;
    if (count <= 0)
        return 0;

    int* ptr = this->groupIDValue;
    int i = 0;

loop:
    if (*ptr != groupId) {
        i = i + 1;
        ptr = ptr + 1;
        if (i < count)
            goto loop;
        return 0;
    }
    return 1;
}
