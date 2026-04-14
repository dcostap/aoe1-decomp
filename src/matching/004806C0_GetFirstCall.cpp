class RGE_TimeSinceLastCall {
public:
    virtual ~RGE_TimeSinceLastCall();
    char gap_0[0x2A4];
    int field_2A8;
    int GetFirstCall();
};

int RGE_TimeSinceLastCall::GetFirstCall() { return this->field_2A8; }
