// VA: 00480480 RGE_TimeSinceLastCall::Set
// PDB source: RGE_TSLC.cpp

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

class RGE_TimeSinceLastCall {
public:
    char TBuff[0x100];
    unsigned long lowTSLC;
    unsigned long highTSLC;
    unsigned long TSLC;
    unsigned long aTSLC[100];
    char gap_29C_29F[4];     // padding/unknown
    int Offset;
    unsigned long LastCall;

    unsigned long Set();
};

unsigned long RGE_TimeSinceLastCall::Set()
{
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x5D);
    unsigned long prev = LastCall;

    if (prev == now)
        return 0;

    LastCall = now;
    TSLC = now - prev;

    int idx = Offset + 1;
    Offset = idx;
    if (idx > 100)
        Offset = 0;

    aTSLC[Offset] = TSLC;

    unsigned long t = TSLC;
    unsigned long lo = lowTSLC;
    if (t < lo)
        lo = t;
    lowTSLC = lo;
    lo = highTSLC;
    if (t > lo)
        lo = t;
    highTSLC = lo;

    return t;
}
