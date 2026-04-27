// VA: 004C7920 addToGroup (162B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual int method_DC(int a1, int a2);
    char gap8[0x60];
    int field_68;
    
    int addToGroup(int groupIndex);
};

int RGE_Static_Object::addToGroup(int groupIndex) {
    if (field_68) {
        int* arr = *(int**)field_68;
        field_68 = groupIndex;
        return 1;
    }
    return 0;
}
