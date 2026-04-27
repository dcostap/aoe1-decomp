// VA: 004536D0 save (1379B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x3C];
    int field_40;
    
    void save(int fd);
};

int __cdecl rge_write(int fd, const void* buf, int size);

void RGE_Master_Static_Object::save(int fd) {
    int val = 0;
    int mask = -1;
    
    if (field_40) {
        val = 1;
    }
    
    rge_write(fd, &val, 4);
}
