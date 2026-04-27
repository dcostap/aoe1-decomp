// VA: 00453120 copy_obj (883B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0xC];
    short field_10;
    short field_12;
    char gap14[0x3A];
    unsigned char field_4E;
    char gap4F[0x3];
    unsigned char field_52;
    
    void copy_obj(RGE_Master_Static_Object* src);
};

void RGE_Master_Static_Object::copy_obj(RGE_Master_Static_Object* src) {
    field_10 = src->field_10;
    field_12 = src->field_12;
    field_52 = src->field_52;
    field_4E = src->field_4E;
}
