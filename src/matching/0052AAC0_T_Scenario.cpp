// MATCHED 2026-05-19. FLAGS: /nologo /c /O2 /GX
// Key fixes: make the base class visibly polymorphic (`virtual ~RGE_Scenario`) so VC5 emits the
// original constructor EH/unwind frame and base-at-zero call shape. Use a small `for (int i=0; i<3; i++)`
// to clear ScenarioOptions; direct repeated stores made VC5 keep ECX as `this`, while the loop source
// collapses to the original `xor ecx,ecx` plus three ECX-based stores before reloading ECX for the final call.

#include "../../include/tscenaro_context.h"

T_Scenario::T_Scenario(RGE_Game_World* world)
    : RGE_Scenario(world) {
    InitializePlayerValues();
    InitializeVictoryValues();
    InitializeFriendlinessValues();
    mp_victory_type = 0;
    victory_score = 900;
    victory_time = 9000;
    victory_all_flag = 0;
    which_player = 0;
    for (int i = 0; i < 3; i++) {
        ScenarioOptions[i] = 0;
    }
    ClearDisabledTechnologies();
}
