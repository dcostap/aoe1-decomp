/* VA: 0050CA9E check_tech_cost (391B)
   no-PDB, C source */
struct TRIBE_Tech {
    int* vtable;
    short field_4;
    int* field_8;
    int* field_C;
};

int TRIBE_Tech_check_tech_cost(struct TRIBE_Tech* this, short idx, int player) {
    int* entry;
    int* playerInfo;
    int threshold;
    
    entry = (int*)((char*)this->field_8 + (signed short)idx * 0x3C);
    playerInfo = this->field_C;
    threshold = *(int*)((char*)playerInfo + 0x50);
    if (entry && threshold > 0) {
        return 1;
    }
    return 0;
}
