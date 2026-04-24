// TRIBE_Panel_Inven::get_help_info
// Returns help text for a screen position. Checks several x-band regions,
// formats the appropriate resource value into the output string.
// tried direct cast expressions instead of named val locals; VC5 still saves __ftol result in edi across get_string
// tried stdio include/prototype context; no change to the sprintf argument evaluation basin

extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" long __cdecl __ftol(void);

extern int TRIBE_Panel_Inven_vftable;

class TPanel {
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
    virtual void vf24(void);
    virtual void vf28(int mode);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void* rect);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(long w, long h);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual int vfBC(long x, long y);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void vfE8(void);
    virtual void vfEC(void);
    virtual void vfF0(void);
    virtual void vfF4(void);
    virtual void vfF8(void);

    char* get_string(int string_id);
};

class TRIBE_Player {
public:
    char gap_00[0x50];
    float* float_values;
};

class TRIBE_Panel_Inven : public TPanel {
public:
    char gap_04[0xF0];
    void* pics;
    TRIBE_Player* player;
    short save_attr_num;
    short gap_FE;
    short* save_attr;

    unsigned char get_help_info(char** out_str, long* out_val, long x, long y);
};

unsigned char TRIBE_Panel_Inven::get_help_info(char** out_str, long* out_val, long x, long y) {
    if (*(int*)((char*)this + 0x6C) == 0)
        return 0;

    if (!this->vfBC(x, y))
        return 0;

    int pnl_x = *(int*)((char*)this + 0x0C);

    if (x < pnl_x + 0x37) {
        int val = (int)this->player->float_values[1];
        sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4EE), val);
        *out_val = -1;
        return 1;
    }

    if (x < pnl_x + 0x6E) {
        int val = (int)this->player->float_values[0];
        sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4ED), val);
        *out_val = -1;
        return 1;
    }

    if (x < pnl_x + 0xA5) {
        int val = (int)this->player->float_values[3];
        sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4EF), val);
        *out_val = -1;
        return 1;
    }

    int val = (int)this->player->float_values[2];
    sprintf(*out_str, ((TPanel*)this)->get_string(0x1D4F0), val);
    *out_val = -1;
    return 1;
}
