// 00545BF0 RGE_Game_World::computerPlayerUpdateTimeAvailable(void)
#include "../world_phase2_context.h"
// World.cpp:3502-3506; owning range 00545BF0-00545BFE.
// The original reads availableComputerPlayerUpdateTime at +0xF8 and returns
// whether its unsigned-long value is nonzero.
int RGE_Game_World::computerPlayerUpdateTimeAvailable() {
    return 0 < this->availableComputerPlayerUpdateTime;
}
