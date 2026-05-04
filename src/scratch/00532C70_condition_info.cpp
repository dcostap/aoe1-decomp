class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[0x2F];
    RGE_Victory_Entry* next;
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* victory_list;

    virtual void vpad0() = 0;
    virtual void vpad1() = 0;
    virtual char* condition_description(RGE_Victory_Entry* entry);

    char condition_info(int index, char** outEntry, unsigned char* outCommand);
};

char RGE_Victory_Conditions::condition_info(int index, char** outEntry, unsigned char* outCommand) {
    RGE_Victory_Entry* entry = this->victory_list;
    int i = 0;
    char* text = 0;

    if (entry) {
        while (entry != 0) {
            if (i == index) {
                text = this->condition_description(entry);
                *outEntry = text;
                *outCommand = entry->command;
                return 1;
            }
            entry = entry->next;
            i++;
        }
    }
    *outEntry = text;
    return 0;
}
