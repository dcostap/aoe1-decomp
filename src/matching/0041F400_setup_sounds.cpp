// VA: 0041F400 RGE_Base_Game::setup_sounds (347 B) EH-framed
// PDB source: basegame.cpp:2653-2676
//
// Attempt log:
// - Replaced the packet scaffold's free constructor/load shims with the
//   period typed TDigital new-expression, named sound array ownership, and
//   external static sound-name symbols.

#include <new.h>

extern "C" void* calloc(unsigned int num, unsigned int size);
extern char s_button1_wav[];
extern char s_button2_wav[];
extern char s_chatrcvd_wav[];

class TSound_Driver;



int RGE_Base_Game::setup_sounds()
{
    TDigital* sound;
    int i;

    this->sound_num = 3;
    this->sounds = (TDigital**)calloc(3, 4);
    if (this->sounds == 0)
        return 0;

    for (i = 0; i < this->sound_num; ++i)
        this->sounds[i] = 0;

    sound = new TDigital(this->sound_system, s_button1_wav, 0xC47C);
    this->sounds[0] = sound;

    sound = new TDigital(this->sound_system, s_button2_wav, 0xC47D);
    this->sounds[1] = sound;

    sound = new TDigital(this->sound_system, s_chatrcvd_wav, 0xC47E);
    this->sounds[2] = sound;

    i = 0;
    for (; i < this->sound_num; ++i) {
        if (this->sounds[i] != 0)
            this->sounds[i]->load(0, -1);
    }

    return 1;
}
