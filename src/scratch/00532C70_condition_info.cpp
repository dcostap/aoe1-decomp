// RGE_Victory_Conditions::condition_info
// VA: 00532C70
// victory.cpp

class RGE_Victory_Entry {
public:
    unsigned char command;    // +0x00
    char gap_01[0x2F];
    RGE_Victory_Entry* next;  // +0x30
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* victory_list; // +0x04 (vtable at +0x00 implicit)

    virtual void vpad0() = 0;
    virtual void vpad1() = 0;
    virtual char* condition_description(RGE_Victory_Entry* entry);

    unsigned char condition_info(long index, RGE_Victory_Entry** outEntry, unsigned char* outCommand);
};

unsigned char RGE_Victory_Conditions::condition_info(long index, RGE_Victory_Entry** outEntry, unsigned char* outCommand) {
    RGE_Victory_Entry* entry = this->victory_list;
    long i = 0;

    if (entry == 0) goto null_entry;

    while (entry != 0) {
        if (i == index) {
            *outEntry = (RGE_Victory_Entry*)this->condition_description(entry);
            *outCommand = entry->command;
            return 1;
        }
        entry = entry->next;
        i++;
    }

    *outEntry = 0;
    return 0;

null_entry:
    *outEntry = 0;
    return 0;
}
