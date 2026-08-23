// VA: 005222C0 TRIBE_Game::setup_sounds
// PDB source: tribegam.cpp
// Attempt: natural /GX setup of 17 TDigital sounds; mirrors RGE_Base_Game::setup_sounds pattern.

extern void* calloc(unsigned int num, unsigned int size);
extern void* operator new(unsigned int size);

class TSound_Driver;

class TDigital {
public:
    char bytes[0x3C];
    TDigital(TSound_Driver* driver, char* file, long resource_id);
    int load(char* name, long param);
};

class TRIBE_Game {
public:
    char gap_00[0x60];
    TSound_Driver* sound_system;   // +0x60
    char gap_64[0x68 - 0x64];
    short sound_num;               // +0x68
    char gap_6A[0x6C - 0x6A];
    TDigital** sounds;             // +0x6C

    int setup_sounds();
};

int TRIBE_Game::setup_sounds()
{
    TDigital* d;
    int i;

    this->sound_num = 17;
    this->sounds = (TDigital**)calloc(17, 4);
    if (this->sounds == 0) {
        return 0;
    }

    for (i = 0; i < this->sound_num; ++i) {
        this->sounds[i] = 0;
    }

#define MAKE_SOUND(slot, nameaddr, resid) \
    d = new TDigital(this->sound_system, (char*)(nameaddr), (resid)); \
    this->sounds[(slot)] = d

    MAKE_SOUND(0, 0x580228, 0xC47C);
    MAKE_SOUND(1, 0x58021C, 0xC47D);
    MAKE_SOUND(2, 0x58020C, 0xC47E);
    MAKE_SOUND(3, 0x58BB8C, 0xC47F);
    MAKE_SOUND(4, 0x58BB80, 0xC480);
    MAKE_SOUND(5, 0x58BB74, 0xC481);
    MAKE_SOUND(6, 0x58BB68, 0xC482);
    MAKE_SOUND(7, 0x58BB58, 0xC483);
    MAKE_SOUND(8, 0x58BB4C, 0xC484);
    MAKE_SOUND(9, 0x58BB40, 0xC485);
    MAKE_SOUND(10, 0x58BB34, 0xC486);
    MAKE_SOUND(11, 0x58BB28, 0xC487);
    MAKE_SOUND(12, 0x58BB1C, 0xC488);
    MAKE_SOUND(13, 0x58BB0C, 0xC489);
    MAKE_SOUND(14, 0x58BAFC, 0xC48A);
    MAKE_SOUND(15, 0x58BAF4, 0xC48B);
    MAKE_SOUND(16, 0x58BAE8, 0xC48C);

#undef MAKE_SOUND

    for (i = 0; i < 3; ++i) {
        if (this->sounds[i] != 0) {
            this->sounds[i]->load(0, -1);
        }
    }

    return 1;
}
