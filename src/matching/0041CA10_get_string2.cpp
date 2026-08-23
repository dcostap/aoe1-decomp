// RGE_Base_Game::get_string2
// VA: 0041CA10
// PDB: basegame.cpp:1265-1325

#include "../../include/game_globals.h"

#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int vf04();
    virtual int vf08();
    virtual int vf0C();
    virtual int vf10();
    virtual int vf14();
    virtual int vf18();
    virtual int vf1C();
    virtual char* get_string(long id, char* buf, int maxlen);
    virtual char* get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5);
};
#endif

// Attempt log:
// - Normal if/else and decrement-cascade forms preserved the call set but put
//   the nested switch inline and produced the wrong first branch topology.
// - An outer switch on param_1, with case 1 containing the param_2 switch and
//   case 2 calling vf20 directly, reproduced the original dec/je/dec/jne
//   dispatch and outlined switch bodies exactly.
// - Ordinary switch breaks (not fallback gotos) retain the exact bytes and the
//   natural common truncation tail. The long parameter spellings match the PDB
//   ABI without changing VC5 output.

char* RGE_Base_Game::get_string2(int param_1, long param_2, long param_3, char* param_4, int param_5)
{
    *param_4 = 0;

    switch (param_1) {
    case 1:
        switch (param_2) {
        case 1: case 2: case 3: case 4: case 5: case 6:
        case 0x0E: case 0x0F:
            return this->get_string(0x7D2, param_4, param_5);
        case 7: case 8: case 0x0B: case 0x0D: case 0x11:
            return this->get_string(0x7D3, param_4, param_5);
        case 0x13:
            return this->get_string(0x7DB, param_4, param_5);
        case 9: case 0x10:
            return this->get_string(0x7D5, param_4, param_5);
        case 0x0A: case 0x0C:
            return this->get_string(0x7D4, param_4, param_5);
        case 0x12:
            return this->get_string(0x7DC, param_4, param_5);
        case 0x14:
            return this->get_string(0x7DD, param_4, param_5);
        case 0x15:
            return this->get_string(0x7DE, param_4, param_5);
        case 0x16:
            return this->get_string(0x7DF, param_4, param_5);
        case 0x17:
            return this->get_string(0x7E0, param_4, param_5);
        default:
            break;
        }
        break;
    case 2:
        return this->get_string(param_2, param_4, param_5);
    default:
        break;
    }

    param_4[param_5 - 1] = 0;
    return param_4;
}
