/* VA: 0050BFED save (781B)
   no-PDB, C source with loop */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
};
int rge_write(int fd, const void* buf, int size);

int TRIBE_Tech_save(struct TRIBE_Tech* this, int fd) {
    short i;
    short value;
    
    rge_write(fd, &this->field_4, 2);
    i = 0;
    while (i < 16) {
        rge_write(fd, &value, 2);
        i++;
    }
    return 1;
}
