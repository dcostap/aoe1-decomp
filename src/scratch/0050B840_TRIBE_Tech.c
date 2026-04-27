/* VA: 0050B840 TRIBE_Tech ctor (836B)
   no-PDB, C source */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
};
int rge_read(int fd, void* buf, int size);

/* Constructor: load tech from file */
int TRIBE_Tech_ctor(struct TRIBE_Tech* this, int fd, int* header) {
    int result;
    
    rge_read(fd, &this->field_4, 2);
    this->field_8 = header;
    result = 1;
    return result;
}
