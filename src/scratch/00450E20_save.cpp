// VA: 00450E20 save (479B)
// m_co_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap4[0xF8];
    int field_FC;
    char gap100[0x8];
    short field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    
    void save(int fd);
};

int __cdecl sub_0044F880(int fd, void* obj);
int __cdecl rge_write(int fd, const void* buf, int size);

void RGE_Master_Combat_Object::save(int fd) {
    sub_0044F880(fd, this);
    
    short val;
    if (field_FC) {
        val = *(short*)((char*)field_FC + 0x72);
    } else {
        val = -1;
    }
    
    rge_write(fd, &val, 2);
}
