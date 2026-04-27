// RGE_Base_Game::get_string2
// VA: 0041CA10
// PDB: basegame.cpp:1265-1325

#include "../../include/game_globals.h"

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
    virtual char* vf20(int id, char* buf, int maxlen);
    virtual char* get_string2(int param_1, int param_2, int param_3, char* param_4, int param_5);
};

// Attempt log:
// pass 1: if/else if with normal conditions → 89.5% diff, cmp/jne not dec/je
// pass 2: --param_1 == 0 cascade → first 13 bytes matched, then jne near vs je short (block layout)
// pass 3: goto approach → same block layout drift; VC5 puts switch inline vs original outline
// pass 4: inverted if → same result
// left in scratch: VC5 block layout drift — original uses `je short` jumping outline to switch body,
//   our VC5 uses `jne near` jumping past inline switch body. Functionally identical but layout differs.
//   Virtual vtable dispatch patterns match (mov edx,[ecx]; call [edx+0x20]).

char* RGE_Base_Game::get_string2(int param_1, int param_2, int param_3, char* param_4, int param_5)
{
    *param_4 = 0;

    if (--param_1 == 0) {
        switch (param_2) {
        case 1: case 2: case 3: case 4: case 5: case 6:
        case 0x0E: case 0x0F:
            return this->vf20(0x7D2, param_4, param_5);
        case 7: case 8: case 0x0B: case 0x0D: case 0x11:
            return this->vf20(0x7D3, param_4, param_5);
        case 9: case 0x10:
            return this->vf20(0x7D5, param_4, param_5);
        case 0x0A: case 0x0C:
            return this->vf20(0x7D4, param_4, param_5);
        case 0x12:
            return this->vf20(0x7DC, param_4, param_5);
        case 0x13:
            return this->vf20(0x7DB, param_4, param_5);
        case 0x14:
            return this->vf20(0x7DD, param_4, param_5);
        case 0x15:
            return this->vf20(0x7DE, param_4, param_5);
        case 0x16:
            return this->vf20(0x7DF, param_4, param_5);
        case 0x17:
            return this->vf20(0x7E0, param_4, param_5);
        }
    } else if (--param_1 == 0) {
        return this->vf20(param_2, param_4, param_5);
    }

    param_4[param_5 - 1] = 0;
    return param_4;
}
