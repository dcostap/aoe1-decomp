#include "../../include/com_spd_context.h"

int RGE_Communications_Speed::GetAvgFrameRate() {
    return this->FrameTSLC->GetAvg(0x32);
}
