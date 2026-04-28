// VA: 00491290 TRIBE_Screen_Campaign_Selection::fillScenarios()
// Source: scr_cams.cpp lines 284-312
// Size: 179 bytes, __thiscall
//
// Attempt log:
// Probe 1-2: ~129 diff bytes, massive register allocation basin
//   rge_base_game loaded into wrong register (8B vs A1 encoding)
//   Arg order for get_scenario_list was swapped initially
//   Two zero-initializations instead of one
// Probe 3: Add RGE_Base_Game* bg = rge_base_game temp → 32 diff bytes!
//   rge_base_game now loaded into eax (A1 encoding) ✓
//   Loop bodies nearly match
//   Prologue/epilogue match
// Probe 4-6: Scope tricks, loop var changes — 32 bytes unchanged
// Remaining 32 diff bytes (17.9%):
//   Arg setup for get_scenario_list: instruction reordering (LEAs vs PUSHes, zero init position)
//   Loop body register allocation (ecx vs eax for scenarios pointer)
//   get_line/set_line reg allocation (eax vs edx for count)
//   All semantically equivalent, pure VC5 scheduling/regalloc basin
// Parked in scratch per Boss direction.

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
