class RGE_Campaign_Info_gsl {
public:
    int get_scenario_list(char*** list, long* count);
};

class RGE_Person_Info_gsl {
public:
    int get_scenario_list(char*** list, long* count);
    char gap_00[0x100];
    int current_campaign;
    char gap_104[0x04];
    RGE_Campaign_Info_gsl** campaign_info;
};

int RGE_Person_Info_gsl::get_scenario_list(char*** list, long* count) {
    if (this->current_campaign > -1)
        return this->campaign_info[this->current_campaign]->get_scenario_list(list, count);
    return 0;
}
