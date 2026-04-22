class RGE_TimeSinceLastCall {
public:
    virtual ~RGE_TimeSinceLastCall();
    char gap_04[0x2AC];
    unsigned long cps;

    unsigned long GetAvg(int count);
    unsigned long CPS();
};

unsigned long RGE_TimeSinceLastCall::CPS() {
    this->cps = 0;
    GetAvg(100);
    return this->cps;
}
