class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x20];
    int field_24;
    void EnableSyncChecking(int v);
};

void RGE_Communications_Synchronize::EnableSyncChecking(int v) { this->field_24 = v; }
