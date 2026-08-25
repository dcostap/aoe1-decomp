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
// probes 9-18: the natural 3-or-1 ternary, explicit byte casts, plain-char
//   locals, mask arithmetic, and buffer-size/order variants did not match.
//   The explicit if/else wave fallback is the source shape that reproduces
//   the oracle's BL neg/sbb/and/inc lowering.
// bounded pause: calls, ownership, offsets, EH frame, and behavior are aligned;
//   remaining drift starts at the music_path local/address schedule.
// - Function-scope music locals, constructor-result-before-path declaration,
//   and direct assignment to the owned music_system field all duplicated the
//   218-byte drift; restored the clean branch-local typed source.
// probe 16: declaring music_path before music_type was a codegen duplicate;
//   restored the clean declaration order after the local-address probe.
// probe 18: plain char music type plus a scoped path buffer was a codegen
//   duplicate; VC5 kept the EBX fallback width and separate path slot.
// probe 19: explicit if/else wave fallback plus direct music_path use matches
//   the original byte-for-byte. The decompiler's +4 labels are stack-variable
//   naming artifacts, not source pointer bias.

#include <stdio.h>



class TSound_Driver;





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
            char music_path[260];

            if (this->prog_info->use_cd_audio != 0)
                music_type = 1;
            else if (this->prog_info->use_midi != 0)
                music_type = 2;
            else if (this->prog_info->use_ima != 0)
                music_type = 4;
            else {
                if (this->prog_info->use_wave_music != 0)
                    music_type = 3;
                else
                    music_type = 1;
            }

            sprintf(music_path, "%s\\%s", this->work_dir,
                    this->prog_info->sounds_dir);

            TMusic_System* music_system =
                new TMusic_System(music_type, this->prog_info->instance, this->prog_window,
                                  this->sound_system, music_path);
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
