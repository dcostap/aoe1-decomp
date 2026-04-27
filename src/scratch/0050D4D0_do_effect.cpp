// 0050D4D0 TRIBE_Effects::do_effect
//
// Attempt log:
// Probes 1-6: various approaches, best was probe 3 (sub/dec in eax, push 0 matched)
//   But register allocation wrong (this saved too early, effect ptr in esi not eax)
// Probe 7: back to explicit sub/dec pattern, pre-compute record_ptr to delay this-save — 83% diff
// Left in scratch: register allocation basin mismatch (7 probes)
//   VC5 chooses eax/es vs ecx for type check, esi vs eax for effect ptr, different register save order

#include "..\..\include\game_globals.h"

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    RGE_Effects(int param);
    virtual void do_effect(short param_1, void* param_2);
};

class TRIBE_Player;

class TRIBE_Effects : public RGE_Effects {
public:
    void* record_ptr;
    int record_count;

    virtual ~TRIBE_Effects();
    TRIBE_Effects(int param);
    virtual void do_effect(short param_1, void* param_2);
    void do_tech_effect(short tech_id, void* player);
};

class TRIBE_Player {
public:
    void tech_abling(long tech_value, unsigned char enable);
};

void TRIBE_Effects::do_effect(short param_1, void* param_2)
{
    int rc = this->record_count;
    if (param_1 >= rc)
        return;

    unsigned char* rp = (unsigned char*)this->record_ptr;
    unsigned char* record = rp + param_1 * 0x2C;

    if (record == 0)
        return;

    short count = *(short*)(record + 0x24);
    if (count > 0) {
        unsigned char* effect = *(unsigned char**)(record + 0x28);
        int i = 0;

        do {
            unsigned long t = (unsigned long)(unsigned char)(*effect);
            if (t != 0x65) {
                t--;
                if (t == 0) {
                    long tech_value = (long)*(float*)(effect + 8);
                    ((TRIBE_Player*)param_2)->tech_abling(tech_value, 0);
                }
            }

            i++;
            effect += 0x0C;
        } while (i < count);
    }

    RGE_Effects::do_effect(param_1, param_2);
}
