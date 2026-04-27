/* VA: 0050C730 tech_cost (878B)
   no-PDB, C source with array stride 0x3C */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
    int* field_C;
};

int TRIBE_Tech_tech_cost(struct TRIBE_Tech* this, short idx, int player) {
    int* entry;
    short i;
    
    entry = (int*)((char*)this->field_8 + (signed short)idx * 0x3C);
    i = 0;
    while (i < 16) {
        if (entry[i] == player) {
            return 1;
        }
        i++;
    }
    return 0;
}
