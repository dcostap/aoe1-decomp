class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[0x1F];
    long count;
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* add(unsigned char id, unsigned char unused);
};

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    unsigned char add_tech(unsigned char id, long count);
};

unsigned char TRIBE_Victory_Conditions::add_tech(unsigned char id, long count) {
    RGE_Victory_Entry* entry;

    entry = this->add(id, 0);
    if (entry != 0) {
        entry->command = 0x64;
        entry->count = count;
        return 1;
    }
    return 0;
}
