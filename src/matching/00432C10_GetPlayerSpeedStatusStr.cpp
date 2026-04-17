class RGE_TimeSinceLastCall {
public:
    char* GetHiLoInfo(int param_1);
};

class RGE_Communications_Speed {
public:
    char gap_00[0x104];
    RGE_TimeSinceLastCall* FrameTSLC;
    char gap_108[0x14];
    unsigned int CurrentBufferFrames;
    unsigned int FutureBufferFrames;
    unsigned int TotalBufferFramesRemaining;
    unsigned int TargetTurnLengthMsec;
    unsigned int CurrentBufferGranularity;

    char* GetPlayerSpeedStatusStr(int player);
};

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern char g_player_speed_status_str[256];
extern const char aBuf3d3dGran3dmsTurn4dms7s[];

char* RGE_Communications_Speed::GetPlayerSpeedStatusStr(int player) {
    unsigned int granularity;
    unsigned int frames;
    char* hi_lo_info;

    if (player < 0 || player > 9) {
        return 0;
    }

    granularity = this->CurrentBufferGranularity;
    frames = this->CurrentBufferFrames;
    hi_lo_info = this->FrameTSLC->GetHiLoInfo(0x32);
    sprintf(
        g_player_speed_status_str,
        aBuf3d3dGran3dmsTurn4dms7s,
        this->TotalBufferFramesRemaining,
        frames,
        granularity,
        frames * granularity,
        hi_lo_info
    );
    return g_player_speed_status_str;
}
