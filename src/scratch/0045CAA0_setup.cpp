// VA: 0045CAA0 setup (862B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x4];
    int field_8;
    
    void setup(int* obj, int a2);
};

int __cdecl sub_0041A310(int* obj, int a2, int a3);

void RGE_Moving_Object::setup(int* obj, int a2) {
    sub_0041A310(obj, a2, (int)obj);
    
    field_8 = (int)obj;
}
