// VA: 004C76C0 findClosestPointInTerrainType (123B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual int method_4();
    char gap8[0x4];
    int field_0C;
    int field_08;
    int field_7C;
    
    int findClosestPointInTerrainType(int x, int y);
};

int RGE_Static_Object::findClosestPointInTerrainType(int x, int y) {
    if (field_7C == -1) {
        int* objInfo = *(int**)((char*)this + 0x0C);
        int* terrainData = *(int**)((char*)this + 0x08);
        if (objInfo && terrainData) {
            field_7C = method_4();
        }
    }
    return field_7C;
}
