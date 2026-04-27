// VA: 0045F9D0 canPath (487B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x8];
    int field_C;
    
    int canPath(int a1);
};

int __cdecl sub_00545D30(int* obj, int a1);

int RGE_Moving_Object::canPath(int a1) {
    int* objInfo = *(int**)((char*)this + 0x0C);
    int* obj = *(int**)((char*)objInfo + 0x3C);
    int result = sub_00545D30(obj, a1);
    
    return result;
}
