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

class TPanel {
public:
    virtual ~TPanel();
#define TPAD(n) virtual void p##n();
    TPAD(1) TPAD(2) TPAD(3) TPAD(4) TPAD(5) TPAD(6) TPAD(7) TPAD(8)
    TPAD(9) TPAD(10) TPAD(11) TPAD(12) TPAD(13) TPAD(14) TPAD(15) TPAD(16)
    TPAD(17) TPAD(18) TPAD(19) TPAD(20) TPAD(21) TPAD(22) TPAD(23) TPAD(24)
    TPAD(25) TPAD(26) TPAD(27) TPAD(28) TPAD(29) TPAD(30) TPAD(31) TPAD(32)
    TPAD(33) TPAD(34) TPAD(35) TPAD(36) TPAD(37) TPAD(38) TPAD(39) TPAD(40)
    TPAD(41) TPAD(42) TPAD(43) TPAD(44) TPAD(45) TPAD(46) TPAD(47) TPAD(48)
    TPAD(49) TPAD(50) TPAD(51) TPAD(52) TPAD(53) TPAD(54) TPAD(55) TPAD(56)
    TPAD(57) TPAD(58) TPAD(59) TPAD(60) TPAD(61) TPAD(62) TPAD(63) TPAD(64)
    TPAD(65) TPAD(66) TPAD(67) TPAD(68) TPAD(69) TPAD(70) TPAD(71) TPAD(72)
    TPAD(73)
#undef TPAD
    char _data[0xF0];
};

class TTextPanel : public TPanel {
public:
    char _gap_F4[0x68];
    int zero_15c;
    void empty_list();
    long get_line(long index);
    void set_line(long line);
    int append_line(char* text, long index);
};

class TListPanel : public TTextPanel {
public:
    void scroll_cur_line(unsigned char dir, short param2, int param3);
};

class TScreenPanel : public TPanel {
public:
    char _gap_F4[0x384];
};

class RGE_Game_Info {
public:
    long get_scenario_list(char*** scenarios, long& count);
};

struct RGE_Base_Game {
    char _gap_00[4];
    RGE_Game_Info* player_game_info;
};

extern RGE_Base_Game* rge_base_game;

#define EPAD(n) virtual void e##n();
class TEasy_Panel : public TScreenPanel {
public:
    EPAD(0) EPAD(1) EPAD(2) EPAD(3) EPAD(4) EPAD(5) EPAD(6) EPAD(7)
    EPAD(8) EPAD(9) EPAD(10) EPAD(11) EPAD(12) EPAD(13) EPAD(14) EPAD(15)
    EPAD(16) EPAD(17) EPAD(18) EPAD(19) EPAD(20) EPAD(21) EPAD(22) EPAD(23)
    EPAD(24) EPAD(25) EPAD(26) EPAD(27) EPAD(28) EPAD(29) EPAD(30) EPAD(31)
    EPAD(32) EPAD(33) EPAD(34) EPAD(35) EPAD(36) EPAD(37) EPAD(38) EPAD(39)
    EPAD(40) EPAD(41) EPAD(42) EPAD(43) EPAD(44)
#undef EPAD
    virtual long vB4(TPanel* panel, long code, unsigned long p3, unsigned long p4);
};

class TRIBE_Screen_Campaign_Selection : public TEasy_Panel {
public:
    TPanel* title;
    int campaignListX;
    int campaignListY;
    int campaignListWidth;
    int campaignListHeight;
    TPanel* campaignTitle;
    TTextPanel* campaignList;
    TPanel* campaignScrollbar;
    int scenarioListX;
    int scenarioListY;
    int scenarioListWidth;
    int scenarioListHeight;
    TPanel* scenarioTitle;
    TTextPanel* scenarioList;
    TPanel* scenarioScrollbar;
    TPanel* difficultyTitle;
    TPanel* difficultyDrop;
    TPanel* okButton;
    TPanel* cancelButton;
    TPanel* close_button;
    int campaignsLoaded;

    void fillScenarios();
};

extern "C" void __cdecl free(void* ptr);

void TRIBE_Screen_Campaign_Selection::fillScenarios() {
    scenarioList->empty_list();

    char** scenarios;
    long currentScenario;
    RGE_Base_Game* bg = rge_base_game;
    scenarios = 0;
    long num = bg->player_game_info->get_scenario_list(&scenarios, currentScenario);

    if (num != 0) {
        long i;
        for (i = 0; i < num; i++) {
            scenarioList->append_line(
                scenarios[i], i);
        }

        long line = scenarioList->get_line(currentScenario);
        scenarioList->set_line(line);

        for (i = 0; i < num; i++) {
            free(scenarios[i]);
        }
        free(scenarios);

        ((TListPanel*)scenarioList)->scroll_cur_line(7, 0, 1);
    }
}
