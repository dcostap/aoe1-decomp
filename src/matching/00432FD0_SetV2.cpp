class TDebuggingLog;

extern TDebuggingLog* L;
extern "C" void __cdecl Log(TDebuggingLog* log, const char* format, unsigned long value);

class RGE_Communications_Speed {
public:
    void SetV2(unsigned long value);
};

void RGE_Communications_Speed::SetV2(unsigned long value) {
    Log(L, "Speed set V2=%d", value);
}
