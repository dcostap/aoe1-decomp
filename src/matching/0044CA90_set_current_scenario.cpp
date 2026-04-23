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

    unsigned char set_current_scenario(long param_1);
};

unsigned char RGE_Campaign_Info::set_current_scenario(long param_1) {
    if (param_1 < scenario_num && scenario_info[param_1].scenario_status != 0) {
        if (param_1 > last_scenario) {
            current_scenario = last_scenario;
        } else {
            current_scenario = param_1;
        }
        return 1;
    }
    return 0;
}
