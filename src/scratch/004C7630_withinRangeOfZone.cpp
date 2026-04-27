// VA: 004C7630 withinRangeOfZone (135B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual int method_4();
    char gap8[0x4];
    int field_0C;
    int field_08;
    char gap10[0x28];
    float field_38;
    float field_3C;
    int field_7C;
    
    int withinRangeOfZone();
};

int RGE_Static_Object::withinRangeOfZone() {
    if (field_7C == -1) {
        int* objInfo = *(int**)((char*)this + 0x0C);
        int* terrainData = *(int**)((char*)this + 0x08);
        if (objInfo && terrainData) {
            field_7C = method_4();
        }
    }
    return field_7C;
}
