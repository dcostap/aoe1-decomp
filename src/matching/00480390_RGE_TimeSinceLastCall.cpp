unsigned long debug_timeGetTime(const char* file, int line);

class RGE_TimeSinceLastCall {
public:
    char gap_00[0x100];
    long lowTSLC;
    long highTSLC;
    char gap_108[0x4];
    long aTSLC[0x65];
    long Offset;
    long LastCall;
    long FirstCall;
    long Now;
    long cps;

    RGE_TimeSinceLastCall();
};

RGE_TimeSinceLastCall::RGE_TimeSinceLastCall() {
    lowTSLC = 0x1869F;
    highTSLC = 0;
    Offset = 0;
    cps = 0;
    long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0xD);
    FirstCall = t;
    Now = t;
    LastCall = t;
    for (int i = 0; i < 0x65; i++)
        aTSLC[i] = 0;
}
