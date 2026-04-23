// tried the direct helper-and-clamp spelling first; if this stays off, the gap is likely just call/branch shape
// keep this compact: one add call, one command store, and the same 1..100 clamp
// if it stays non-exact, the remaining difference is likely the return/branch basin rather than behavior

class RGE_Victory_Entry;

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* add(unsigned char param_1, unsigned char param_2);
    unsigned char add_explore(unsigned char param_1, long param_2, unsigned char param_3);
};

class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[3];
    long obj_type;
    void* target_player;
    float x0;
    float y0;
    float x1;
    float y1;
    long number;
    long count;
};

unsigned char RGE_Victory_Conditions::add_explore(unsigned char param_1, long param_2, unsigned char param_3) {
    RGE_Victory_Entry* entry = this->add(param_1, param_3);
    if (entry != 0) {
        entry->command = 7;
        if (param_2 < 1) {
            param_2 = 1;
        }
        if (100 < param_2) {
            param_2 = 100;
        }
        entry->count = param_2;
        return 1;
    }
    return 0;
}
