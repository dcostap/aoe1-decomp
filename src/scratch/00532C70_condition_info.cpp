// tried the direct list walk and callback-object spelling; mismatch stayed at the prolog/register-save basin
// kept the same branch structure, but switching the output pointer to the more literal entry-pointer form
// leaving in scratch: the remaining delta is low-level codegen shape around the early null-guard and loop setup

class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[0x2F];
    RGE_Victory_Entry* next;
};

class RGE_Victory_Entry_Helper {
public:
    virtual void* vf00(void);
    virtual void* vf04(void);
    virtual RGE_Victory_Entry* vf08(RGE_Victory_Entry* entry);
};

class RGE_Victory_Conditions {
public:
    char gap_00[4];
    RGE_Victory_Entry* victory_list;

    unsigned char condition_info(long index, RGE_Victory_Entry** outEntry, unsigned char* outCommand);
};

unsigned char RGE_Victory_Conditions::condition_info(long index, RGE_Victory_Entry** outEntry, unsigned char* outCommand) {
    RGE_Victory_Entry* entry = this->victory_list;
    long i = 0;
    if (entry == 0) {
        *outEntry = 0;
        return 0;
    }
    while (entry != 0) {
        if (i == index) {
            *outEntry = ((RGE_Victory_Entry_Helper*)*outEntry)->vf08(entry);
            *outCommand = entry->command;
            return 1;
        }
        entry = entry->next;
        i++;
    }
    *outEntry = 0;
    return 0;
}
