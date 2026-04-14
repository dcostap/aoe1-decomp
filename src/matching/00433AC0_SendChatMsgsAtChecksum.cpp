class RGE_Communications_Synchronize {
public:
    virtual ~RGE_Communications_Synchronize();
    char gap_0[0x10];
    int field_14;
    void SendChatMsgsAtChecksum(int v);
};

void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int v) { this->field_14 = v; }
