// TRIBE_Panel_Inven::save_info
// Syncs save_attr array with player's ability values.
// reshaped with top zero/index and goto allocation path; prolog/loop now in the target basin
// remaining first mismatch is the original's redundant cmp eax,edi / je before free; VC5 still removes it from this source

extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

extern int TRIBE_Panel_Inven_vftable;

class TRIBE_Player {
public:
    char gap_00[0x4C];
    short field_4C;
    char gap_4E[0x02];
    float* field_50;
};

class TRIBE_Panel_Inven {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    char gap_04[0xF0];
    void* pics;
    TRIBE_Player* player;
    short save_attr_num;
    short gap_FE;
    short* save_attr;

    void save_info();
};

void TRIBE_Panel_Inven::save_info() {
    int iVar3 = 0;
    short* psVar2 = this->save_attr;
    if (psVar2 != (short*)0) {
        if (this->save_attr_num == this->player->field_4C)
            goto fill_values;
        if (psVar2 != (short*)0) {
            free(psVar2);
            this->save_attr = (short*)0;
        }
    }
    this->save_attr_num = this->player->field_4C;
    this->save_attr = (short*)calloc((int)this->save_attr_num, 2);

fill_values:
    if (this->save_attr_num > iVar3) {
        do {
            int next = iVar3 + 1;
            this->save_attr[iVar3] = (short)(int)this->player->field_50[iVar3];
            iVar3 = next;
        } while (iVar3 < this->save_attr_num);
    }
}
