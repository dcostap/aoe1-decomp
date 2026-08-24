// 0040A420 BaseObject::inGroup
// PDB: aibobj.cpp:212-217, 50 bytes
// __thiscall, ret 4

#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[0x08];
    int count;
    int* groups;

    int inGroup(int groupId) const;
};
#endif

int BaseObject::inGroup(int groupId) const {
    int n = this->count;
    int i = 0;
    while (i < n) {
        if (this->groups[i] == groupId) return 1;
        i++;
    }
    return 0;
}
