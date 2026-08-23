// TRIBE_Game::get_string2
// VA: 00522930
// PDB: tribegam.cpp:957-1118
// Signature: virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5)
//   __thiscall, ret 0x14. EXACT MATCH (0.0000% diff).
//
// Attempt log:
// - baseline: cases in PDB source order (100,101,105,102,1,103,104), vf20=get_string(long,char*,int)
//   slot8, base-call default. Calls 89/89 aligned immediately; 42.5% diff was case 103's dispatch.
// - case103 probes: if-chains in several orders never matched. VC5 emits `cmp 65h; jg; je; dec; jne`
//   for a single SPARSE SWITCH on param_2 whose low cluster {1,0x65} and high cluster {0x66..0x6A,1000}
//   are lowered by VC5 as compare-chain + sub/table dispatch. The `je` reuses the switch bound check's
//   flags; the `dec` is the min-case normalization for case 1. Guarded if/switch forms emit the tests
//   in ascending order instead (dec;je;sub;je) and inline the early returns, which does not match.
// - switch case order must follow the PDB line order (1, 0x68, 1000, 0x65, 0x66, 0x67, 0x69, 0x6A)
//   so the case bodies land in the original emission order.
// - ranges: `<= 0x65`/`<= 0x3E8` not needed; single switch reproduces cmp-65h/jg directly.
//
// Key facts:
// - virtual slot 8 (vtable+0x20) is get_string(long, char*, int); calls write into param_4.
// - unhandled (param_1, param_2) pairs fall to RGE_Base_Game::get_string2 (0041CA10) direct call.
// - tail `param_4[param_5-1]=0; return param_4;` mirrors sibling get_string (005228E0).

#include "../../include/tribegam_context.h"

#if 0
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message, unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int value);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int param_1, long param_2, char* param_3, int param_4); // vt[7] @0x1C
    virtual char* get_string(long param_1, char* param_2, int param_3);             // vt[8] @0x20
    virtual char* get_string(long param_1);                                         // vt[9] @0x24
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5); // vt[10] @0x28
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5);
};
#endif

char* TRIBE_Game::get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5)
{
    *param_4 = 0;

    switch (param_1) {
    case 100:
        switch (param_2) {
        case 0: case 0x0F: case 0x10: case 0x11:
            return this->get_string(0x10CD, param_4, param_5);
        case 1:
            return this->get_string(0x10CE, param_4, param_5);
        case 2:
            return this->get_string(0x10CF, param_4, param_5);
        case 3:
            return this->get_string(0x10D0, param_4, param_5);
        case 9:
            return this->get_string(0x10DB, param_4, param_5);
        }
        break;
    case 101:
        switch (param_2) {
        case 1:
            return this->get_string(0x1069, param_4, param_5);
        case 2:
            return this->get_string(0x106A, param_4, param_5);
        case 3:
            return this->get_string(0x106B, param_4, param_5);
        case 4:
            return this->get_string(0x106C, param_4, param_5);
        }
        break;
    case 105:
        switch (param_2) {
        case 1:
            this->get_string(0x27F7, param_4, param_5);
            break;
        case 2:
            this->get_string(0x27F8, param_4, param_5);
            break;
        case 3:
            this->get_string(0x27F9, param_4, param_5);
            break;
        case 4:
            this->get_string(0x27FA, param_4, param_5);
            break;
        case 5:
            this->get_string(0x27FB, param_4, param_5);
            break;
        case 6:
            this->get_string(0x27FC, param_4, param_5);
            break;
        case 7:
            this->get_string(0x27FD, param_4, param_5);
            break;
        case 8:
            this->get_string(0x27FE, param_4, param_5);
            break;
        case 9:
            this->get_string(0x27FF, param_4, param_5);
            break;
        case 10:
            this->get_string(0x2800, param_4, param_5);
            break;
        case 11:
            this->get_string(0x2801, param_4, param_5);
            break;
        case 12:
            this->get_string(0x2802, param_4, param_5);
            break;
        case 13:
            this->get_string(0x2806, param_4, param_5);
            break;
        case 14:
            this->get_string(0x2807, param_4, param_5);
            break;
        case 15:
            this->get_string(0x2809, param_4, param_5);
            break;
        case 16:
            this->get_string(0x2808, param_4, param_5);
            break;
        default:
            this->get_string(0x2804, param_4, param_5);
            break;
        }
        break;
    case 102:
        switch (param_2) {
        case 1:
            return this->get_string(0x1005, param_4, param_5);
        case 2:
            return this->get_string(0x1006, param_4, param_5);
        case 3:
            return this->get_string(0x1007, param_4, param_5);
        case 4:
            return this->get_string(0x1008, param_4, param_5);
        case 5:
            return this->get_string(0x1009, param_4, param_5);
        case 6:
            return this->get_string(0x100A, param_4, param_5);
        case 7:
            return this->get_string(0x100B, param_4, param_5);
        case 8:
            return this->get_string(0x100C, param_4, param_5);
        case 9:
            return this->get_string(0x100D, param_4, param_5);
        case 10:
            return this->get_string(0x100E, param_4, param_5);
        case 11:
            return this->get_string(0x100F, param_4, param_5);
        case 12:
            return this->get_string(0x1010, param_4, param_5);
        case 13:
            return this->get_string(0x1011, param_4, param_5);
        case 14:
            return this->get_string(0x1012, param_4, param_5);
        case 15:
            return this->get_string(0x1013, param_4, param_5);
        case 16:
            return this->get_string(0x1014, param_4, param_5);
        case 17:
            return this->get_string(0x1015, param_4, param_5);
        case 18:
            return this->get_string(0x1016, param_4, param_5);
        case 19:
            return this->get_string(0x1017, param_4, param_5);
        case 20:
            return this->get_string(0x1018, param_4, param_5);
        case 21:
            return this->get_string(0x1019, param_4, param_5);
        case 22:
            return this->get_string(0x101A, param_4, param_5);
        case 23:
            return this->get_string(0x101B, param_4, param_5);
        case 0x1C:
            return this->get_string(0x101C, param_4, param_5);
        case 0x1D:
            return this->get_string(0x101D, param_4, param_5);
        case 0x1E:
            return this->get_string(0x101E, param_4, param_5);
        case 0x1F:
            return this->get_string(0x101F, param_4, param_5);
        case 0x19:
            return this->get_string(0x1020, param_4, param_5);
        case 0x1A:
            return this->get_string(0x1021, param_4, param_5);
        case 0x1B:
            return this->get_string(0x1022, param_4, param_5);
        case 0x20:
            return this->get_string(0x1025, param_4, param_5);
        case 0x21:
            return this->get_string(0x1026, param_4, param_5);
        }
        break;
    case 1:
        switch (param_2) {
        case 0x64: case 0x65: case 0x66:
            return this->get_string(0x961, param_4, param_5);
        case 0x67:
            return this->get_string(0x962, param_4, param_5);
        case 0x68:
            return this->get_string(0x963, param_4, param_5);
        case 0x69:
            return this->get_string(0x964, param_4, param_5);
        case 0x6A:
            return this->get_string(0x965, param_4, param_5);
        default:
            return RGE_Base_Game::get_string2(param_1, param_2, param_3, param_4, param_5);
        }
    case 103:
        switch (param_2) {
        case 1:
            switch (param_3) {
            case 4:
                return this->get_string(0xBBD, param_4, param_5);
            case 0:
                return this->get_string(0xBB9, param_4, param_5);
            case 1:
                return this->get_string(0xBBA, param_4, param_5);
            case 2:
                return this->get_string(0xBBB, param_4, param_5);
            case 3:
                return this->get_string(0xBBC, param_4, param_5);
            case 0x20:
                return this->get_string(0xBE6, param_4, param_5);
            }
            break;
        case 0x68:
            return this->get_string(0xBC1, param_4, param_5);
        case 1000:
            return this->get_string(0xBC2, param_4, param_5);
        case 0x65:
            return this->get_string(0xBBE, param_4, param_5);
        case 0x66:
            return this->get_string(0xBBF, param_4, param_5);
        case 0x67:
            return this->get_string(0xBC0, param_4, param_5);
        case 0x69:
            return this->get_string(0xBC3, param_4, param_5);
        case 0x6A:
            return this->get_string(0xBCA, param_4, param_5);
        }
        break;
    case 104:
        switch (param_2) {
        case 2:
            return this->get_string(0x10D1, param_4, param_5);
        case 3:
            return this->get_string(0x10D2, param_4, param_5);
        case 4:
            return this->get_string(0x10D3, param_4, param_5);
        case 1:
            return this->get_string(0x10D4, param_4, param_5);
        case 5:
            return this->get_string(0x10D5, param_4, param_5);
        case 6:
            return this->get_string(0x10D6, param_4, param_5);
        case 7:
            return this->get_string(0x10D7, param_4, param_5);
        case 8:
            return this->get_string(0x10D8, param_4, param_5);
        case 9:
            return this->get_string(0x10D9, param_4, param_5);
        case 10:
            return this->get_string(0x10DA, param_4, param_5);
        case 11:
            return this->get_string(0x10DC, param_4, param_5);
        }
        break;
    default:
        return RGE_Base_Game::get_string2(param_1, param_2, param_3, param_4, param_5);
    }

    param_4[param_5 - 1] = 0;
    return param_4;
}
