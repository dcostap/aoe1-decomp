class RGE_Victory_Entry;

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* field_0;
    RGE_Victory_Entry* victory_list;

    void sub(RGE_Victory_Entry* entry);
    void destroy_all();
};

void RGE_Victory_Conditions::destroy_all() {
    RGE_Victory_Entry* entry;

    entry = this->victory_list;
    while (entry != 0) {
        sub(entry);
        entry = this->victory_list;
    }
}
