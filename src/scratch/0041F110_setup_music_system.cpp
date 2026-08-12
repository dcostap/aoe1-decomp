// VA: 0041F110 RGE_Base_Game::setup_music_system (442 B)
// PDB source: basegame.cpp lines 2558-2624
//
// Attempt log:
// baseline: packet scaffold had free-function shims and an extra prog_info-null
//   guard; it matched size/frame but not the member-call targets or entry CFG.
// probe 2: restored the period typed RGE_Base_Game/RGE_Prog_Info/TMusic_System/
//   TRegistry surfaces and natural new/delete/member calls; checking next.
// probes 3-5: /GX plus direct prog_info rereads restored the EH frame, all nine
//   decorated call targets, the 0x10C frame, and the threshold cmp/jg; the
//   remaining localized gap is source-local music_path scheduling.
// probes 6-8: direct-negation, unsigned-mask, and multiply spellings for the
//   wave fallback were non-exact; the multiply variant was closer but not kept.
// probe 9: a natural 3-or-1 ternary reproduces the oracle's neg/sbb/and/inc
//   idiom at the correct full-function size; the explicit byte cast was a
//   codegen duplicate and is omitted from the clean source.
// bounded pause: calls, ownership, offsets, EH frame, and behavior are aligned;
//   remaining drift starts at the music_path local/address schedule.
// - Function-scope music locals, constructor-result-before-path declaration,
//   and direct assignment to the owned music_system field all duplicated the
//   218-byte drift; restored the clean branch-local typed source.

#include <stdio.h>

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class TSound_Driver;

class TMusic_System {
public:
    char gap_000[0x104];
    unsigned char music_type;             // +0x104
    char gap_105[3];
    TSound_Driver* sound_system;           // +0x108
    void* instance;                        // +0x10C
    void* window;                          // +0x110
    int device_open;                       // +0x114
    char gap_118[0x248 - 0x118];
    int track_count;                       // +0x248
    char gap_24C[0x3F8 - 0x24C];

    TMusic_System(unsigned char type, void* instance, void* window,
                  TSound_Driver* sound, char* path);
    ~TMusic_System();
    int set_music_type(unsigned char type);
    void set_volume(long volume, int flag);
};

class TRegistry {
public:
    int RegGetInt(int use_user, const char* name);
};

class RGE_Prog_Info {
public:
    char gap_000[0x410];
    void* instance;                         // +0x410
    char gap_414[0x8A4 - 0x414];
    int use_music;                          // +0x8A4
    int use_sound;                          // +0x8A8
    int use_cd_audio;                       // +0x8AC
    int use_ima;                            // +0x8B0
    int use_midi;                           // +0x8B4
    int use_wave_music;                     // +0x8B8
    char gap_8BC[0xE21 - 0x8BC];
    char sounds_dir[0x105];                 // +0xE21
};

class RGE_Base_Game {
public:
    char gap_004[0x0C - 0x04];
    RGE_Prog_Info* prog_info;               // +0x0C
    void* prog_window;                       // +0x10
    char gap_014[0x60 - 0x14];
    TSound_Driver* sound_system;            // +0x60
    TMusic_System* music_system;            // +0x64
    char gap_068[0x1AC - 0x68];
    TRegistry* registry;                     // +0x1AC
    char gap_1B0[0x1E8 - 0x1B0];
    char work_dir[0x105];                    // +0x1E8

    VPAD16(a)
    VPAD4(b)
    VPAD2(c)
    virtual int setup_music_system();        // slot 22, vtable +0x58
};

int RGE_Base_Game::setup_music_system()
{
    if (this->prog_info->use_music != 0) {
        int volume = -5000;
        int result = this->registry->RegGetInt(1, "Music Volume");
        if (result != -1)
            volume = -result;

        if (volume <= -0x26AC) {
            this->prog_info->use_music = 0;
            TMusic_System* music = this->music_system;
            if (music != 0) {
                delete music;
                this->music_system = 0;
            }
        }
        else if (this->music_system == 0) {
            unsigned char music_type;

            if (this->prog_info->use_cd_audio != 0)
                music_type = 1;
            else if (this->prog_info->use_midi != 0)
                music_type = 2;
            else if (this->prog_info->use_ima != 0)
                music_type = 4;
            else
                music_type = this->prog_info->use_wave_music != 0 ? 3 : 1;

            char music_path[260];
            sprintf(music_path + 4, "%s\\%s", this->work_dir,
                    this->prog_info->sounds_dir);

            TMusic_System* music_system =
                new TMusic_System(music_type, this->prog_info->instance, this->prog_window,
                                  this->sound_system, music_path + 4);
            this->music_system = music_system;

            if (music_system != 0 && music_type == 1 &&
                this->prog_info->use_cd_audio == 0) {
                if (music_system->device_open == 0 ||
                    music_system->track_count < 2) {
                    if (music_system->set_music_type(2) == 0)
                        this->music_system->set_music_type(3);
                }
            }

            if (this->music_system != 0)
                this->music_system->set_volume(volume, 1);
        }
    }

    return 1;
}
