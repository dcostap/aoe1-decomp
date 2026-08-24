#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Campaign {
public:
    int open_scenario(int index);
};

class RGE_Campaign_Info {
public:
    char gap_00[0x100];
    int current_scenario;
    char gap_104[0xC];
    RGE_Campaign* campaign;

    int open_scenario();
};
#endif

int RGE_Campaign_Info::open_scenario() {
    if (this->current_scenario > -1) {
        return this->campaign->open_scenario(this->current_scenario);
    }
    return -1;
}
