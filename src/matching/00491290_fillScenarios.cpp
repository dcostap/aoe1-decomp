// VA: 00491290 TRIBE_Screen_Campaign_Selection::fillScenarios()
// Source: scr_cams.cpp lines 284-312
// Size: 179 bytes, __thiscall
//
// Attempt log:
// Probe 1-2: ~129 diff bytes, massive register allocation basin
//   rge_base_game loaded into wrong register (8B vs A1 encoding)
//   Arg order for get_scenario_list was swapped initially
//   Two zero-initializations instead of one
// Probe 3: Add RGE_Base_Game* bg = rge_base_game temp -> 32 diff bytes.
//   rge_base_game now loaded into eax (A1 encoding), loop bodies nearly match, prologue/epilogue match.
// Probe 4-6: Scope tricks, loop var changes -> 32 bytes unchanged.
// 2026-05-21 retry: tried count/scenarios declaration order, late zero, separate Game_Info temp, no bg temp,
// comma-expression zeroing in call args, volatile scenarios, flags /Ob0 /O2-no-/Oy /Oa /O1 /G5, list local
// all/inner-only, text/free temps, and explicit do loops. No variant improved the 179B / 17.8771% positional
// baseline. Remaining drift: get_scenario_list arg setup scheduling (LEAs/pushes/zero init), loop-body register
// allocation for scenarios pointer/text arg, and get_line/free argument register choice. Calls, stack cleanup, and
// behavior line up, but drift is still spread across several setup/call hunks, so left in scratch rather than
// accepted_drift.
// 2026-05-26 Boss pass: 17 more probes. Revalidated current best (179B, 17.8771% positional, first mismatch +24).
// Tried no-init plus late scenarios=0, comma-arg zeroing, reversed get_scenario_list prototype, count-first local order,
// inline rge_base_game, text/free pointer temps, flags /Ob0 /Og /Ot /G5 /Oa, local frame structs in both field orders,
// explicit do loops, panel local, and no line local. All useful variants stayed in the same 179B basin except inline/panel/Oa
// regressions. GIVEUP: no accepted_drift because remaining drift spans get_scenario_list LEA/push/zero scheduling plus
// loop argument register choices; not localized benign drift.
// 2026-08-03 Luna491290 session (10 meaningful hypotheses):
// - Reconstructed the PDB-visible currentScenario output alias and tested long**
//   versus char*** / long& call surfaces; emitted code stayed at 32 bytes diff.
// - Tested comma-expression output initialization, full proven UI inheritance
//   context, and <stdlib.h> CRT context; all were codegen duplicates.
// - Focused pointer-shape lab (225 size/frame/call-set variants) found four
//   basins; the best natural basin remained 179 bytes / 32 positional bytes.
// - Focused setup-order lab (7 variants) found no setup improvement; direct
//   bg-local source remained the only size/frame/call-set basin.
// Final clean-source restore: remaining drift is distributed across the
// get_scenario_list LEA/push/zero setup and loop register coloring (append,
// get_line, and free), with all eight calls, frame, size, and CFG aligned.
// 2026-08-03 Luna491290b follow-up:
// - corrected the ABI surfaces to get_scenario_list(char***, long&), CRT _free,
//   append_line(char*, long), and scroll_cur_line(unsigned char, short, int);
//   these fixed relocation identity without changing emitted bytes.
// - restored the generated TPanel/TScreenPanel/TEasy/TTextPanel owner layout;
//   exact class context was a codegen duplicate of the 179-byte basin.
// - direct rge_base_game access regressed to a 180-byte structural basin; the
//   cached bg local remains the only natural A1/global-load basin.
// - a 64-variant natural pointer/loop/text/context lab found no closer basin;
//   union output alias was diagnostic only and was rolled back.
// Final source retains the natural scenario-pointer/currentScenario reconstruction; 32-byte
// distributed codegen drift remains across setup and loop register coloring.
// 2026-08-07 orch-w10: EXACT MATCH (0.0000%) after mirroring the exact sibling donor
//   004911A0 fillCampaigns: cache the FIELD local (RGE_Game_Info* info =
//   rge_base_game->player_game_info) instead of the global bg, initialize
//   scenarios = 0 in its declaration, and call through info. VC5 then loads the
//   global into EAX (A1), schedules mov ecx,[eax+4] between the two arg pushes,
//   and reuses EAX for the &scenarios LEA — the previously unreachable basin.
// probe-027 context: reduced the generated TPanel/TScreenPanel/TEasy vtable-pad
//   surface to the sibling-style flat class (scenarioList at +0x4AC via
//   campaignList +0x490 + gap 0x18); still exact, kept as the final source.
// Final: minimal flat surface + field-local call shape; exact match verified.

#include <stdlib.h>

class RGE_Game_Info {
public:
    long get_scenario_list(char*** scenarios, long& count);
};

class RGE_Base_Game {
public:
    char _gap_00[4];
    RGE_Game_Info* player_game_info;    // +0x04
};

extern RGE_Base_Game* rge_base_game;

class TTextPanel {
public:
    void empty_list();
    int append_line(char* text, long value);
    long get_line(long index);
    void set_line(long line);
    void scroll_cur_line(unsigned char dir, short param2, int param3);
};

class TRIBE_Screen_Campaign_Selection {
public:
    char _gap_000[0x490];
    TTextPanel* campaignList;           // +0x490
    char _gap_018[0x18];
    TTextPanel* scenarioList;           // +0x4AC

    void fillScenarios();
};

extern "C" void __cdecl free(void* ptr);

void TRIBE_Screen_Campaign_Selection::fillScenarios() {
    scenarioList->empty_list();

    RGE_Game_Info* info = rge_base_game->player_game_info;
    char** scenarios = 0;
    long currentScenario;

    long num = info->get_scenario_list(&scenarios, currentScenario);

    if (num != 0) {
        long i;
        for (i = 0; i < num; i++) {
            scenarioList->append_line(scenarios[i], i);
        }

        long line = scenarioList->get_line(currentScenario);
        scenarioList->set_line(line);

        for (i = 0; i < num; i++) {
            free(scenarios[i]);
        }
        free(scenarios);

        scenarioList->scroll_cur_line(7, 0, 1);
    }
}
