// VA: 0048FE80 TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list()
// Source: scr_cam.cpp lines 298-317
// Size: 119 bytes, __thiscall

class TTextPanel {
public:
    void empty_list();
    int append_line(const char* text, int index);
};

class RGE_Campaign {
public:
    long scenario_info(char*** list);
};

class TRIBE_Campaign_Editor_Screen {
public:
    char _gap_00[0x490];
    TTextPanel* campaign_scenarios;  // +0x490
    char _gap_494[0x2C];
    RGE_Campaign* campaign;          // +0x4C0

    void fill_campaign_scenario_list();
};

void __cdecl free(void* ptr);

void TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list() {
    if (this->campaign == 0)
        return;

    this->campaign_scenarios->empty_list();

    char** scenario_names;
    long count = this->campaign->scenario_info(&scenario_names);

    if (scenario_names != 0) {
        long i;
        for (i = 0; i < count; i++) {
            this->campaign_scenarios->append_line(scenario_names[i], 0);
            free(scenario_names[i]);
        }
        free(scenario_names);
    }
}
