// first pass: preserve the exact scenario-status update order and the follow-up cap
// tried the direct <= cap form; the remaining gap collapsed to the compare operand order in the cap check
#ifndef GAMEINFO_SHARED_CONTEXT
#include "..\..\include\game_types.h"

class RGE_Scenario_Info {
public:
    unsigned char scenario_status;
};

class RGE_Campaign_Info {
public:
    char campaign_name[0x100];
    long current_scenario;
    long scenario_num;
    RGE_Scenario_Info* scenario_info;
    long last_scenario;

    void set_current_scenario(long scenario_index);
    void notify_of_scenario_complete(void);
};
#endif

void RGE_Campaign_Info::notify_of_scenario_complete(void) {
    if (this->current_scenario > -1) {
        this->scenario_info[this->current_scenario].scenario_status = 1;

        if (this->last_scenario <= this->current_scenario) {
            this->last_scenario = this->current_scenario + 1;
            this->set_current_scenario(this->last_scenario);
        }

        if (this->last_scenario >= this->scenario_num) {
            this->last_scenario = this->scenario_num - 1;
        }

        this->scenario_info[this->last_scenario].scenario_status = 2;
    }
}
