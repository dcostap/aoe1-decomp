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

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(int param_1);
    virtual long get_size();
    virtual void save(int);
};

extern void rge_read_uncompressed(int, void*, int);

TRIBE_Scenario_Header::TRIBE_Scenario_Header(int param_1)
    : RGE_Scenario_Header((RGE_Scenario*)param_1) {
    any_sp_victory = 0;
    active_player_count = 0;
    if (error_code == 0) {
        rge_read_uncompressed(param_1, &any_sp_victory, 4);
        rge_read_uncompressed(param_1, &active_player_count, 4);
    }
}
