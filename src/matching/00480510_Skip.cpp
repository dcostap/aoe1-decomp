extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class RGE_TimeSinceLastCall {
public:
    char gap_00[0x2A4];
    unsigned long LastCall;

    void Skip(void);
};

void RGE_TimeSinceLastCall::Skip(void) {
    debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x78);
    this->LastCall = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x79);
}
