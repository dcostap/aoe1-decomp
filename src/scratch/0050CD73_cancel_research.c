/* VA: 0050CD73 cancel_research (245B)
   no-PDB, C source */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
};
int rge_write(int fd, const void* buf, int size);

int TRIBE_Tech_cancel_research(struct TRIBE_Tech* this, short idx, int fd) {
    int* entry;
    short* base;
    int result;
    
    entry = (int*)((char*)this->field_8 + (signed short)idx * 0x3C);
    base = (short*)entry;
    result = rge_write(fd, base, 4);
    if (result == 0) {
        return 0;
    }
    return 1;
}
