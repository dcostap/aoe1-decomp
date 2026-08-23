// 00545BC0 RGE_Game_World::useComputerPlayerUpdateTime(unsigned long)
// World.cpp:3492-3497; owning range 00545BC0-00545BE5.
// The original reads +0xF8, clamps it to zero, or stores the loaded value minus amount.
class RGE_Game_World {
public:
    char gap_0[0xF8];
    unsigned long availableComputerPlayerUpdateTime;
    void useComputerPlayerUpdateTime(unsigned long);
};

void RGE_Game_World::useComputerPlayerUpdateTime(unsigned long amount) {
    if (this->availableComputerPlayerUpdateTime < amount) {
        this->availableComputerPlayerUpdateTime = 0;
    } else {
        this->availableComputerPlayerUpdateTime -= amount;
    }
}
