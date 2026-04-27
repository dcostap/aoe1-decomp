/* VA: 0050CC25 start_research (334B)
   no-PDB, C source */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
};
int rge_write(int fd, const void* buf, int size);

int TRIBE_Tech_start_research(struct TRIBE_Tech* this, short idx, int player, int a4) {
    int* entry;
    int result;
    
    entry = (int*)((char*)this->field_8 + (signed short)idx * 0x3C);
    result = rge_write(player, entry, 4);
    if (result == 0) {
        return 0;
    }
    return 1;
}
