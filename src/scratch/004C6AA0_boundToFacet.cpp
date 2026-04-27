// VA: 004C6AA0 boundToFacet (162B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual int method_DC(int a1, int a2);
    char gap8[0x4];
    int field_0C;
    int field_08;
    char gap10[0x14];
    int field_1C;
    char gap20[0x10];
    float field_30;
    
    void boundToFacet(int param1);
};

void RGE_Static_Object::boundToFacet(int param1) {
    if (field_1C) {
        method_DC(-1, 0);
    }
}
