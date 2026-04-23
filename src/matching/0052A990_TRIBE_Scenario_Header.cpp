class RGE_Scenario;
class RGE_Scenario_Header {
public:
    int error_code;
    long version;
    unsigned long checksum;
    char* description;

    RGE_Scenario_Header(RGE_Scenario*);
    virtual long get_size();
    virtual void save(int);
    virtual ~RGE_Scenario_Header();
};

class RGE_Scenario {
public:
    int active_player_count();
};

class T_Scenario : public RGE_Scenario {
public:
    int any_sp_victory();
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(T_Scenario* scenario);
    virtual long get_size();
    virtual void save(int);
};

TRIBE_Scenario_Header::TRIBE_Scenario_Header(T_Scenario* scenario)
    : RGE_Scenario_Header(scenario) {
    any_sp_victory = scenario->any_sp_victory();
    active_player_count = scenario->active_player_count();
}
