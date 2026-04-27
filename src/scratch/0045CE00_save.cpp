// VA: 0045CE00 save (639B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    char gap4[0x88];
    int field_8C;
    
    void save(int fd);
};

int __cdecl sub_0041A3D0(void* this_, int fd);
int __cdecl rge_write(int fd, const void* buf, int size);

void RGE_Moving_Object::save(int fd) {
    sub_0041A3D0(this, fd);
    
    rge_write(fd, &field_8C, 4);
}
