// VA: 004E8D20 VictoryConditionRuleSystem::modifyForDifficultyLevel
// Attempt log:
// try 1: used helper scale_min1; compiled too short (672B vs 969B) because repeated scale/test blocks were factored away.
// try 2: expanded all scale_min1 sites inline to mirror original repeated fild/fmul/ftol/test/store/min1 blocks.

extern "C" long __cdecl ftol(float);
class RGE_Base_Game { public: int expansionRule(); };
extern RGE_Base_Game* rge_base_game;

class VictoryConditionRuleSystem {
public:
    char gap00[0x44]; int f44; char gap48[0x08]; int f50; int f54; char gap58[0x10]; int f68; int f6c; char gap70[4]; int f74;
    char gap78[0x1c]; int f94; char gap98[4]; int f9c; char gapa0[0x1c]; int fbc; char gapc0[4]; int fc4;
    char gapc8[0x24]; int fec; int ff0; int ff4; char gapf8[0x18]; int f110; int f114; int f118;
    char gap11c[0x48]; int f164; char gap168[0x38]; int f1a0; int f1a4;
    void modifyForDifficultyLevel(int level);
};

void VictoryConditionRuleSystem::modifyForDifficultyLevel(int level)
{
    int add1 = 0, add2 = 0, add3 = 0;
    float scale1 = 1.0f, scale2 = 1.0f;
    int tmp;
    if (!level) return;
    switch (level) {
    case 1:
        if (rge_base_game->expansionRule() == 1) { scale1 = 0.8f; add1 = 30; scale2 = 0.8f; add2 = 120; add3 = 1; }
        break;
    case 2:
        scale1 = 0.6f; add1 = 60; scale2 = 0.6f; add2 = 240; add3 = 2; break;
    case 3:
        scale1 = 0.4f; add1 = 90; scale2 = 0.4f; add2 = (rge_base_game->expansionRule() == 1) ? 360 : 900; add3 = 3; break;
    case 4:
        scale1 = 0.2f; add1 = 120; scale2 = 0.2f; add2 = (rge_base_game->expansionRule() == 1) ? 480 : 1260; add3 = 4; break;
    default: return;
    }

    tmp = this->f94; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f94 = tmp; if (!tmp) this->f94 = 1; }
    tmp = this->f44; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f44 = tmp; if (!tmp) this->f44 = 1; }
    tmp = this->f6c; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f6c = tmp; if (!tmp) this->f6c = 1; }
    this->fbc += add1; this->fc4 += add1;
    tmp = this->f50; if (tmp > 0) { tmp = ftol((float)tmp * scale2); this->f50 = tmp; if (!tmp) this->f50 = 1; }
    tmp = this->f54; if (tmp > 0) { tmp = ftol((float)tmp * scale2); this->f54 = tmp; if (!tmp) this->f54 = 1; }
    this->f1a4 += add2;
    tmp = this->f68; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f68 = tmp; if (!tmp) this->f68 = 1; }
    tmp = this->f74; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f74 = tmp; if (!tmp) this->f74 = 1; }
    tmp = this->f9c; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f9c = tmp; if (!tmp) this->f9c = 1; }
    tmp = this->fec; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->fec = tmp; if (!tmp) this->fec = 1; }
    tmp = this->ff0; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->ff0 = tmp; if (!tmp) this->ff0 = 1; }
    tmp = this->ff4; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->ff4 = tmp; if (!tmp) this->ff4 = 1; }
    tmp = this->f110; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f110 = tmp; if (!tmp) this->f110 = 1; }
    tmp = this->f114; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f114 = tmp; if (!tmp) this->f114 = 1; }
    tmp = this->f118; if (tmp > 0) { tmp = ftol((float)tmp * scale1); this->f118 = tmp; if (!tmp) this->f118 = 1; }
    this->f164 += add3;
    if (level <= 3) this->f1a0 = 1; else this->f1a0 = 0;
}
