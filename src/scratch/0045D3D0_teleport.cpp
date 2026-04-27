// VA: 0045D3D0 teleport (491B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x10];
    int field_1C;
    
    void teleport(int x, int y);
};

void RGE_Moving_Object::teleport(int x, int y) {
    int* obj = *(int**)field_8;
    if (!obj) return;
    unsigned char flag = *(unsigned char*)((char*)obj + 0xCC);
    if (!flag) return;
    
    int* dest = *(int**)field_1C;
    if (dest) {
        dest[0] = x;
        dest[1] = y;
    }
}
