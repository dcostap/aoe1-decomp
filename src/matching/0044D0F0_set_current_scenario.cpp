// BINARY NOTE: gameinfo.cpp lines 423-427 test current_campaign against -1,
// then index campaigns at +110 and campaign_info at +108.
// Attempt log: >= 0 emitted test/jl and 52 bytes (45 differing).  The > -1
// guard restored cmp -1/jle.  The canonical fallback member order then gave
// the exact 53-byte body in standalone and grouped checks.

#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Campaign_Info {
public:
    virtual ~RGE_Campaign_Info();
    char gap_0[0xFC];
    int field_100;
    unsigned char set_current_scenario(long scenario);
};

class RGE_Campaign;

class RGE_Person_Info {
public:
    char gap_00[0x100];
    int current_campaign;
    char gap_104[0x4];
    RGE_Campaign_Info** campaign_info;
    int campaign_num;
    RGE_Campaign** campaigns;

    unsigned char set_current_scenario(long scenario);
};
#endif

unsigned char RGE_Person_Info::set_current_scenario(long scenario) {
    int current_campaign = this->current_campaign;
    if ((current_campaign > -1) && (this->campaigns[current_campaign] != 0)) {
        return this->campaign_info[current_campaign]->set_current_scenario(scenario);
    }
    return 0;
}
