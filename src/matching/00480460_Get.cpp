extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class RGE_TimeSinceLastCall {
public:
    virtual ~RGE_TimeSinceLastCall();
    char gap_04[0x2A0];
    unsigned long LastCall;

    unsigned long Get();
};

unsigned long RGE_TimeSinceLastCall::Get() {
    return debug_timeGetTime("C:\\msdev\\work\\age1_x1\\RGE_TSLC.cpp", 0x56) - this->LastCall;
}
