// VA: 0045FBC0 canBidirectionPath (779B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x8];
    int field_C;
    
    int canBidirectionPath(int a1);
};

int __cdecl sub_00545D30(int* obj, int a1);

int RGE_Moving_Object::canBidirectionPath(int a1) {
    int* objInfo = *(int**)((char*)this + 0x0C);
    int* obj = *(int**)((char*)objInfo + 0x3C);
    int result = sub_00545D30(obj, a1);
    
    return result;
}
