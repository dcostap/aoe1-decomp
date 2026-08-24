#include "../../include/com_spd_context.h"

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern char g_self_player_optimal_speed_str[152];
extern const char aMeOptimalBuf3dGran3dTargetFps3dLatency3d[];

char* RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(void) {
    unsigned int frames;
    unsigned int granularity;

    frames = this->GetRecommendedBufferFrames();
    granularity = this->GetRecommendedBufferGranularity();
    sprintf(
        g_self_player_optimal_speed_str,
        aMeOptimalBuf3dGran3dTargetFps3dLatency3d,
        frames,
        granularity,
        1000 / (int)granularity,
        granularity * frames
    );
    return g_self_player_optimal_speed_str;
}
