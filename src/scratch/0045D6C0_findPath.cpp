// VA: 0045D6C0 findPath (1232B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    int findPath(int x, int y);
};

int RGE_Moving_Object::findPath(int x, int y) {
    int* obj = *(int**)field_8;
    if (!obj) return 0;
    
    float f = *(float*)((char*)obj + 0x38);
    
    return (int)f;
}
