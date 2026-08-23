// VA: 004E8D20 VictoryConditionRuleSystem::modifyForDifficultyLevel (969B)
// taistrmd.cpp
//
// Attempt log:
// baseline reset: canonical VictoryConditionRuleSystem::sn ownership, the
// period scenarioGame() helper, natural guarded switch, and repeated minimum-1
// FPU scaling blocks. Earlier source used expansionRule(), an explicit
// float-argument ftol wrapper, and top-level initialized locals; those forms
// changed the call set, introduced stack arguments, or allocated the frame too
// early and were not retained.

class RGE_Base_Game {
public:
    int scenarioGame();
};

extern RGE_Base_Game* rge_base_game;

#include "../../include/taistrmd_context.h"

struct ScaleLocals {
    float scale1;
    float scale2;
    int tmp;
};

void VictoryConditionRuleSystem::modifyForDifficultyLevel(int level)
{
    if (level != 0) {
        int add1 = 0;
        int add2 = 0;
        int add3 = 0;
        // The three fields mirror the binary-proven contiguous local window:
        // scale1 at [esp+10h], scale2 at [esp+14h], and tmp at [esp+18h].
        ScaleLocals locals;
        locals.scale1 = 1.0f;
        locals.scale2 = 1.0f;

        switch (level) {
        case 1:
            if (rge_base_game->scenarioGame() == 1) {
                locals.scale1 = 0.8f;
                add1 = 30;
                locals.scale2 = 0.8f;
                add2 = 120;
                add3 = 1;
            }
            break;
        case 2:
            locals.scale1 = 0.6f;
            add1 = 60;
            locals.scale2 = 0.6f;
            add2 = 240;
            add3 = 2;
            break;
        case 3:
            locals.scale1 = 0.4f;
            add1 = 90;
            locals.scale2 = 0.4f;
            add2 = (rge_base_game->scenarioGame() == 1) ? 360 : 900;
            add3 = 3;
            break;
        case 4:
            locals.scale1 = 0.2f;
            add1 = 120;
            locals.scale2 = 0.2f;
            add2 = (rge_base_game->scenarioGame() == 1) ? 480 : 1260;
            add3 = 4;
            break;
        default:
            return;
        }

        locals.tmp = this->sn[0x24];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x24] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x24] = 1;
            }
        }
        locals.tmp = this->sn[0x10];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x10] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x10] = 1;
            }
        }
        locals.tmp = this->sn[0x1A];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x1A] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x1A] = 1;
            }
        }

        this->sn[0x2E] += add1;
        this->sn[0x30] += add1;

        locals.tmp = this->sn[0x13];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale2);
            this->sn[0x13] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x13] = 1;
            }
        }
        locals.tmp = this->sn[0x14];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale2);
            this->sn[0x14] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x14] = 1;
            }
        }

        this->sn[0x68] += add2;

        locals.tmp = this->sn[0x19];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x19] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x19] = 1;
            }
        }
        locals.tmp = this->sn[0x1C];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x1C] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x1C] = 1;
            }
        }
        locals.tmp = this->sn[0x26];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x26] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x26] = 1;
            }
        }
        locals.tmp = this->sn[0x3A];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x3A] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x3A] = 1;
            }
        }
        locals.tmp = this->sn[0x3B];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x3B] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x3B] = 1;
            }
        }
        locals.tmp = this->sn[0x3C];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x3C] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x3C] = 1;
            }
        }
        locals.tmp = this->sn[0x43];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x43] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x43] = 1;
            }
        }
        locals.tmp = this->sn[0x44];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x44] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x44] = 1;
            }
        }
        locals.tmp = this->sn[0x45];
        if (locals.tmp > 0) {
            locals.tmp = (long)((float)locals.tmp * locals.scale1);
            this->sn[0x45] = locals.tmp;
            if (locals.tmp == 0) {
                this->sn[0x45] = 1;
            }
        }

        this->sn[0x58] += add3;
        if (level <= 3) {
            this->sn[0x67] = 1;
        } else {
            this->sn[0x67] = 0;
        }
    }
}
