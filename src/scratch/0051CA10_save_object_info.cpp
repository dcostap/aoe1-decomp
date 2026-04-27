// VA: 0051CA10 save_object_info (620B)
// tpnl_obj.cpp

class TRIBE_Panel_Object {
public:
    char gap4[0x11C];
    unsigned char field_120;
    char gap121[0x3];
    int field_124;
    
    void save_object_info(int fd);
};

void TRIBE_Panel_Object::save_object_info(int fd) {
    if (field_120 != 2) return;
    
    field_124 = 1;
}
