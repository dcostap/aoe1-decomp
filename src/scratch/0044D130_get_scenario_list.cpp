class RGE_Campaign_gsl {
public:
    int get_scenario_list(int a, int b);
};

class RGE_Campaign_Info_gsl {
public:
    int get_scenario_list(int a, int b);
    char gap_00[0x100];
    int current_person;
    char gap_104[0x04];
    void** campaigns;
};

int RGE_Campaign_Info_gsl::get_scenario_list(int a, int b) {
    int idx = this->current_person;
    if (idx <= -1) return 0;
    return ((RGE_Campaign_gsl*)this->campaigns[idx])->get_scenario_list(a, b);
}
