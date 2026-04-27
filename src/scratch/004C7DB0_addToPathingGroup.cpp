// VA: 004C7DB0 addToPathingGroup (145B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual int method_DC(int a1, int a2);
    char gap8[0x50];
    int field_58;
    char gap5C[0xC];
    int field_68;
    
    int addToPathingGroup(int groupIndex);
};

int RGE_Static_Object::addToPathingGroup(int groupIndex) {
    if (field_58) {
        field_68 = groupIndex;
        return 1;
    }
    return 0;
}
