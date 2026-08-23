// VA: 00540D30 RGE_Game_World::pause (45 B)
// PDB-qualified owner/name: public: virtual void __thiscall RGE_Game_World::pause(unsigned char)
// PDB source: World.cpp lines 366-375
// Original body boundary: 00540D30-00540D5C; next symbol: 00540D60.
// BINARY NOTE: The paused guard precedes the signed sound-count test. The loop
// rereads sound_num after each RGE_Sound::stop call, preserving call and fault order.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::pause(unsigned char paused) {
    int i;

    if (paused != 0) {
        i = 0;
        if (this->sound_num > 0) {
            do {
                this->sounds[i]->stop();
                i = i + 1;
            } while (i < this->sound_num);
        }
    }
}
