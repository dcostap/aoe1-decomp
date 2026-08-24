// VA: 0047C2F0 TTextPanel::setup
// PDB source: Pnl_txt.cpp

#ifndef PNL_TXT_TU_CONTEXT
class TDrawArea;
class TPanel {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc();
    virtual void ve0(char** p16, short p17);
    long setup(TDrawArea* draw, TPanel* parent, long p3, long p4, long p5, long p6, int zero);
};

class TTextPanel : public TPanel {
public:
    char gap_04[0x134];
    short fixed_len;      // +138
    char gap_13a[0x12];
    char* fill_back;      // +14c
    unsigned char back_color; // +150
    char gap_151[3];
    int outline;          // +154
    unsigned char outline_color; // +158
    char gap_159[0x17];
    int bevel_type;       // +170

    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4,
               long param_5, long param_6, void* param_7, long param_8,
               long param_9, char* param_10, int param_11, unsigned char param_12,
               int param_13, unsigned char param_14, short param_15,
               char** param_16, short param_17);
    void set_font(void* param_7, long param_8, long param_9);
    void set_alignment(int a, int b);
    void set_back_pic(char* p);
};
#endif

long TTextPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4,
                       long param_5, long param_6, void* param_7, long param_8,
                       long param_9, char* param_10, int param_11, unsigned char param_12,
                       int param_13, unsigned char param_14, short param_15,
                       char** param_16, short param_17)
{
    TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0);
    this->fill_back = (char*)param_11;
    this->back_color = param_12;
    this->outline = param_13;
    this->outline_color = param_14;
    this->fixed_len = param_15;
    if (param_13 != 0) {
        this->bevel_type = 1;
    }
    this->ve0(param_16, param_17);
    this->set_font(param_7, param_8, param_9);
    this->set_alignment(3, 1);
    this->set_back_pic(param_10);
    return 1;
}
