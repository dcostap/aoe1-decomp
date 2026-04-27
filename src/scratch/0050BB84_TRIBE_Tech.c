/* VA: 0050BB84 TRIBE_Tech ctor (932B)
   no-PDB, C source with fopen + loop */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
    int* field_C;
};
int sub_54BBA0(const char* filename, const char* mode);
int rge_read(int fd, void* buf, int size);

int TRIBE_Tech_ctor_2(struct TRIBE_Tech* this, const char* filename) {
    int fd;
    int count;
    short val;
    
    this->vtable = 0;
    fd = sub_54BBA0(filename, "rb");
    if (fd == 0) {
        return 0;
    }
    rge_read(fd, &this->field_4, 2);
    count = 0;
    while (count < 16) {
        rge_read(fd, &val, 2);
        count++;
    }
    return 1;
}
