class RGE_TimeSinceLastCall {
public:
    ~RGE_TimeSinceLastCall(void);
};

void operator_delete(void* ptr);

class RGE_Communications_Speed {
public:
    char gap_00[0x100];
    RGE_TimeSinceLastCall* TurnTSLC;
    RGE_TimeSinceLastCall* FrameTSLC;

    ~RGE_Communications_Speed(void);
};

RGE_Communications_Speed::~RGE_Communications_Speed(void) {
    RGE_TimeSinceLastCall* tslc;

    tslc = this->FrameTSLC;
    if (tslc != 0) {
        tslc->~RGE_TimeSinceLastCall();
        operator_delete(tslc);
    }

    tslc = this->TurnTSLC;
    if (tslc != 0) {
        tslc->~RGE_TimeSinceLastCall();
        operator_delete(tslc);
    }
}
