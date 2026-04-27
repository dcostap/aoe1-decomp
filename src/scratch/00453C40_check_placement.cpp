// VA: 00453C40 check_placement (1909B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x62];
    short field_66;
    
    int check_placement(int* obj, unsigned char flags);
};

int RGE_Master_Static_Object::check_placement(int* obj, unsigned char flags) {
    int* objInfo = *(int**)((char*)obj + 0x3C);
    int w = *(int*)((char*)objInfo + 0x54);
    int h = *(int*)((char*)objInfo + 0x28);
    
    short myVal = field_66;
    
    if (flags) {
        field_66 = (short)w;
        return 1;
    }
    return 0;
}
