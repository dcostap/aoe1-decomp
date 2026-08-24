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

#ifndef BASEGAME_GROUPED_TU
class TDigital {
public:
    TSound_Driver* sound_system;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char sound_file[13];
    unsigned char gap_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    unsigned char* wave_data;
    void* wave_info;
    void* sound_buffer;
    unsigned long data_size;

    TDigital(TSound_Driver* driver, char* file, long resource_id);
    int load(char* name, long param);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_004[0x5C];
    TSound_Driver* sound_system;
    char gap_064[0x68 - 0x64];
    short sound_num;
    char gap_06A[0x6C - 0x6A];
    TDigital** sounds;

    int setup_sounds();
};
#endif

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
