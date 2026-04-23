extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

class RGE_TimeSinceLastCall {
public:
    unsigned long GetAvg(int value);
    char* GetAvgInfo(int value);
};

char* RGE_TimeSinceLastCall::GetAvgInfo(int value) {
    unsigned long avg;
    int count;

    count = value;
    avg = GetAvg(count);
    sprintf((char*)this, "Avg %d / %d", avg, count);
    return (char*)this;
}
