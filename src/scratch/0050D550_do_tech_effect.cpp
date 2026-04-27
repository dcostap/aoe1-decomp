// 0050D550 TRIBE_Effects::do_tech_effect
//
// Probe 1: pointer-increment — 81% diff
// Probe 2: offset-based calc, int count — 71% diff
// Probe 3: short count for word compare — 70% diff
// Left in scratch: same register allocation basin mismatch as do_effect (3 probes)

#include "..\..\include\game_globals.h"

class TRIBE_Player;

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    RGE_Effects(int param);
};

class TRIBE_Effects : public RGE_Effects {
public:
    void* record_ptr;
    int record_count;

    virtual ~TRIBE_Effects();
    TRIBE_Effects(int param);
    virtual void do_effect(short param_1, void* param_2);
    void do_tech_effect(short tech_id, TRIBE_Player* player);
};

class TRIBE_Player {
public:
    void tech_abling(long tech_value, unsigned char enable);
};

void TRIBE_Effects::do_tech_effect(short tech_id, TRIBE_Player* player)
{
    unsigned char* record = (unsigned char*)this->record_ptr + tech_id * 0x2C;
    short count = *(short*)(record + 0x24);
    int i = 0;

    if (count > 0) {
        unsigned char* effect_list = *(unsigned char**)(record + 0x28);
        int offset = 0;

        do {
            unsigned char* effect = effect_list + offset;
            unsigned long t = (unsigned long)(unsigned char)(*effect);

            t -= 0x65;
            if (t != 0) {
                t--;
                if (t == 0) {
                    long tech_value = (long)*(float*)(effect + 8);
                    player->tech_abling(tech_value, 0);
                }
            }

            i++;
            offset += 0x0C;
        } while (i < count);
    }
}
