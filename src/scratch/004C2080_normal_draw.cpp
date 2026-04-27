// VA: 004C2080 normal_draw (137B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap4[0x18];
    int field_1C;
    char gap20[0x16];
    char field_36;
    char gap37[0x11];
    char field_48;
    
    void normal_draw(int a1, int a2);
};

void RGE_Static_Object::normal_draw(int a1, int a2) {
    if (!field_1C) return;
    if ((unsigned char)field_48 >= 7) return;
}
