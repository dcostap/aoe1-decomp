class TRIBE_Player_Tech {
public:
    short get_tech_state(short tech);
};

struct RGE_Victory_Entry {
    char gap_00[0x20];
    short count;
    char gap_22[0x0C];
    unsigned char state;
};

struct VictoryInfo {
    char gap_00[0x220];
    TRIBE_Player_Tech* techs;
};

class TRIBE_Victory_Conditions {
public:
    char gap_00[0x0C];
    VictoryInfo* info;

    void handle_tech(RGE_Victory_Entry* entry);
};

void TRIBE_Victory_Conditions::handle_tech(RGE_Victory_Entry* entry) {
    if ((this->info != 0) && (entry->state == 0)) {
        if (this->info->techs->get_tech_state(entry->count) == 3) {
            entry->state = 2;
        }
    }
}
