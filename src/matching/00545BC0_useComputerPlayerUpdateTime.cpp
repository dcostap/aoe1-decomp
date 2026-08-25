// 00545BC0 RGE_Game_World::useComputerPlayerUpdateTime(unsigned long)
#include "../world_phase2_context.h"
// World.cpp:3492-3497; owning range 00545BC0-00545BE5.
// The original reads +0xF8, clamps it to zero, or stores the loaded value minus amount.
void RGE_Game_World::useComputerPlayerUpdateTime(unsigned long amount) {
    if (this->availableComputerPlayerUpdateTime < amount) {
        this->availableComputerPlayerUpdateTime = 0;
    } else {
        this->availableComputerPlayerUpdateTime -= amount;
    }
}
