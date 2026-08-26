#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Campaign_Info {
public:
    virtual ~RGE_Campaign_Info();
    char gap_0[0xFC];
    int field_100;
    long get_current_scenario();
};
#endif

long RGE_Campaign_Info::get_current_scenario() { return this->current_scenario; }
