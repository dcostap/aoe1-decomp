// VA: 00460210 findFirstTerrainAlongExceptionPath (406B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0xD4];
    int field_D8;
    
    int findFirstTerrainAlongExceptionPath(int a1);
};

int __cdecl sub_0046ADC0(void* this_);

int RGE_Moving_Object::findFirstTerrainAlongExceptionPath(int a1) {
    int result = sub_0046ADC0((char*)this + 0xD8);
    if (result < 2) return 0;
    
    return result;
}
