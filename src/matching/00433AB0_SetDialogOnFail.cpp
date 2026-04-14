class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0xC];
    int field_10;
    void SetDialogOnFail(int v);
};

void RGE_Communications_Synchronize::SetDialogOnFail(int v) { this->field_10 = v; }
