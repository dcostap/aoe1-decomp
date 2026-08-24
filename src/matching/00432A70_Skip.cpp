#include "../../include/com_spd_context.h"

void RGE_Communications_Speed::Skip(void) {
    FrameTSLC->Skip();
    LastFrameHadTime = 0;
}
