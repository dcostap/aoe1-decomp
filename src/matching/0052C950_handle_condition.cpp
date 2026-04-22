struct RGE_Victory_Entry {
    unsigned char command;
};

class RGE_Victory_Conditions {
public:
    virtual void handle_condition(RGE_Victory_Entry* entry);
};

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    void handle_tech(RGE_Victory_Entry* entry);
    void handle_condition(RGE_Victory_Entry* entry);
};

void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* entry) {
    if (entry->command != 'd') {
        RGE_Victory_Conditions::handle_condition(entry);
        return;
    }
    handle_tech(entry);
}
