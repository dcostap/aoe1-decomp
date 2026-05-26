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

class TListPanel {
public:
    void scroll_cur_line(unsigned char dir, int param2, int param3);
    char _gap[4];
};

class TTextPanel : public TListPanel {
public:
    void empty_list();
    long get_line(long index);
    void set_line(long line);
    int append_line(const char* text, int index);
};

class RGE_Game_Info {
public:
    long get_scenario_list(char*** scenarios, long* count);
};

struct RGE_Base_Game {
    char _gap_00[4];
    RGE_Game_Info* player_game_info;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Campaign_Selection {
public:
    char _gap_00[0x4AC];
    TTextPanel* scenarioList;

    void fillScenarios();
};

void __cdecl free(void* ptr);

void TRIBE_Screen_Campaign_Selection::fillScenarios() {
    scenarioList->empty_list();

    char** scenarios = 0;
    long count;
    RGE_Base_Game* bg = rge_base_game;
    long num = bg->player_game_info->get_scenario_list(&scenarios, &count);

    if (num != 0) {
        long i;
        for (i = 0; i < num; i++) {
            scenarioList->append_line(scenarios[i], i);
        }

        long line = scenarioList->get_line(count);
        scenarioList->set_line(line);

        for (i = 0; i < num; i++) {
            free(scenarios[i]);
        }
        free(scenarios);

        scenarioList->scroll_cur_line(7, 0, 1);
    }
}
