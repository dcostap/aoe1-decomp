// VA: 0041F030 RGE_Base_Game::setup_sound_system (224 B) EH-framed
// PDB source: basegame.cpp lines 2527-2552
// /GX: EH frame with new-expression state stores at [esp+18h] (0 -> -1)
//
// Canonical ownership:
//   RGE_Base_Game: prog_info +0x0C, prog_window +0x10, sound_system +0x60,
//                  registry +0x1AC; virtual setup_music_system at vtable+0x58.
//   RGE_Prog_Info: use_sound +0x8A8 (int), sounds_dir +0xE21 (char[]).
//   TSound_Driver: 0x69C bytes (operator new size); ctor(prog_window, sounds_dir),
//                  driver_active(), ~TSound_Driver(), set_volume(volume, 1).
//   TRegistry::RegGetInt(1, "Sound Volume").
//   Global sound_driver at 0x62C4B0.
//
// Attempt log:
// probe 1 (baseline): canonical classes RGE_Base_Game/TSound_Driver/TRegistry/RGE_Prog_Info,
//   new-expression + delete, sound_driver global, /GX rsp. diff=189; all 8 calls aligned
//   (100%). Remaining drift: prologue missing push ebx and every zero-compare/zero-store
//   used test/C7 instead of the original's cmp X,edi / mov [mem],edi register-zero forms.
//   Root cause: VC5 reused the volume's edi for the destroy pointer (volume declared at top
//   is const-0 until its neg, so the destroy path reuses edi; no ebx save).
// probes 2-8: long volume, delete w/o guard, member-only accesses, driver-variable reuse,
//   sound_system=(TSound_Driver*)volume, explicit dtor+operator_delete temp, combined &&
//   condition — all byte-identical (VC5 IR invariant to these shapes).
// probe 9 (match): move `int volume = 0;` AFTER the destroy block, right before the
//   RegGetInt/set_volume region. VC5 then keeps edi as the function-wide zero register
//   (xor hoisted to the use_sound check, exactly like the original's 2529 line record),
//   allocates ebx for the destroy pointer, and assigns the late volume to the already-zero
//   edi. Exact match (0.0000%).
// Left in matching: the late-declared volume is the binary-proven original shape.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

#ifndef BASEGAME_GROUPED_TU
class TSound_Driver {
public:
    char gap_0[0x69C];
    TSound_Driver(void* hwnd, char* sounds_dir);
    ~TSound_Driver();
    int driver_active();
    void set_volume(long volume, int param_2);
};

class TRegistry {
public:
    int RegGetInt(int use_user, const char* name);
};

class RGE_Prog_Info {
public:
    char gap_0[0x8A8];
    int use_sound;                     // +0x8A8
    char gap_8AC[0xE21 - 0x8AC];
    char sounds_dir[0x80];             // +0xE21
};

extern TSound_Driver* sound_driver;    // 0x62C4B0

class RGE_Base_Game {
public:
    char gap_4[0x0C - 0x04];           // vptr +0
    RGE_Prog_Info* prog_info;          // +0x0C
    void* prog_window;                 // +0x10
    char gap_14[0x60 - 0x14];
    TSound_Driver* sound_system;       // +0x60
    char gap_64[0x1AC - 0x64];
    TRegistry* registry;               // +0x1AC
    VPAD16(a)                          // vtable slots 0..15
    VPAD4(b)                           // slots 16..19
    VPAD2(c)                           // slots 20..21
    virtual int setup_music_system();  // slot 22 = vtable+0x58
    int setup_sound_system();
};
#endif

int RGE_Base_Game::setup_sound_system()
{
    if (this->prog_info->use_sound != 0) {
        TSound_Driver* driver = new TSound_Driver(this->prog_window, this->prog_info->sounds_dir);
        this->sound_system = driver;
        if (driver != 0 && driver->driver_active() == 0) {
            if (this->sound_system != 0) {
                delete this->sound_system;
            }
            this->sound_system = 0;
            return 1;
        }
        sound_driver = this->sound_system;
        int volume = 0;
        int result = this->registry->RegGetInt(1, "Sound Volume");
        if (result != -1) {
            volume = -result;
        }
        this->sound_system->set_volume(volume, 1);
    }
    this->setup_music_system();
    return 1;
}
