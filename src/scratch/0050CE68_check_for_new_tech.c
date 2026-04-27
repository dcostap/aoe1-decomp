/* VA: 0050CE68 check_for_new_tech (530B)
   no-PDB, C source with loop */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
};

int TRIBE_Tech_check_for_new_tech(struct TRIBE_Tech* this) {
    int* base;
    short i;
    unsigned char found;
    
    base = this->field_8;
    found = 0;
    i = 0;
    while (i < 16) {
        if (base[i] > 0) {
            found = 1;
        }
        i++;
    }
    if (found) {
        return 1;
    }
    return 0;
}
