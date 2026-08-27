#ifndef RGE_TSLC_H
#define RGE_TSLC_H

class RGE_TimeSinceLastCall {
public:
    char TBuff[256];
    unsigned long lowTSLC;
    unsigned long highTSLC;
    unsigned long TSLC;
    unsigned long aTSLC[101];
    int Offset;
    unsigned long LastCall;
    unsigned long FirstCall;
    unsigned long Now;
    unsigned long cps;

    RGE_TimeSinceLastCall();
    ~RGE_TimeSinceLastCall();
    unsigned long GetAvg(int count);
    unsigned long Get();
    unsigned long Set();
    void Skip();
    char* GetAvgInfo(int count);
    char* GetHiLoMaxInfo(int count);
    char* GetHiLoInfo(int count);
    unsigned long CPS();
    unsigned long GetFirstCall();
    char* GetElapsedFirstCall();
    void Test();
};

#endif
