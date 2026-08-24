// VA: 0041F830 RGE_Base_Game::stop_sound_system (229 B)
// PDB source: basegame.cpp lines 2774-2809
// Default flags.
//
// Reconstruction notes:
// - Same-TU exact donor 0041F920 restart_sound_system provides the world-sound
//   loop spelling (sound_num at world+0x2C, sounds at world+0x30) and the
//   chat/panel_system global spellings.
// - Class surface mirrors RGE_Base_Game layout from the generated type
//   reference: vptr, sound_system +0x60, sound_num +0x68, sounds +0x6C,
//   registry +0x1AC, world +0x3F4.
// - Virtual call at vtable+0x5C modeled via padded declared-only virtuals.
// - sound_driver global at 62C4B0 zeroed last.

#ifndef BASEGAME_GROUPED_TU
extern void* chat;            // 62C4B8
extern int panel_system;      // 62E870
extern int sound_driver;      // 62C4B0

void operator delete(void* p);
extern "C" void __cdecl free(void* block);

class TChat {
public:
    void StopSoundSystem(void);
};

class TPanelSystem {
public:
    void stop_sound_system(void);
};

class TDigital {
public:
    ~TDigital();
};

class TSound_Driver {
public:
    int get_volume(void);
    ~TSound_Driver();
};

class TRegistry {
public:
    int RegSetInt(int useUserKey, const char* valueName, int value);
};

class RGE_Base_Game {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);

    char gap_04[0x5C];           // +0x04
    TSound_Driver* sound_system; // +0x60
    char gap_64[4];              // +0x64
    short sound_num;             // +0x68
    char gap_6A[2];              // +0x6A
    TDigital** sounds;           // +0x6C
    char gap_70[0x1AC - 0x70];   // +0x70
    TRegistry* registry;         // +0x1AC
    char gap_1B0[0x3F4 - 0x1B0]; // +0x1B0
    void* world;                 // +0x3F4

    void stop_sound_system(void);
};
#endif

class RGE_Sound {
public:
    void restart_sound(void* driver);
};

void RGE_Base_Game::stop_sound_system(void) {
    if (chat != 0) {
        ((TChat*)chat)->StopSoundSystem();
    }

    ((TPanelSystem*)&panel_system)->stop_sound_system();

    if (this->world != 0) {
        int i = 0;
        if (*(short*)((char*)this->world + 0x2C) > 0) {
            do {
                ((RGE_Sound*)(*(void**)(*(int*)((char*)this->world + 0x30) + i * 4)))->restart_sound(0);
                i++;
            } while (i < (int)(short)*(short*)((char*)this->world + 0x2C));
        }
    }

    if (this->sounds != 0) {
        int i = 0;
        if (this->sound_num > 0) {
            do {
                TDigital* snd = this->sounds[i];
                if (snd != 0) {
                    snd->~TDigital();
                    operator delete(snd);
                }
                i++;
            } while (i < this->sound_num);
        }
        free(this->sounds);
        this->sounds = 0;
    }

    this->vf5C();

    if (this->sound_system != 0) {
        this->registry->RegSetInt(1, "Sound Volume", -this->sound_system->get_volume());
        TSound_Driver* driver = this->sound_system;
        if (driver != 0) {
            driver->~TSound_Driver();
            operator delete(driver);
        }
        this->sound_system = 0;
        sound_driver = 0;
    }
}
