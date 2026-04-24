// attempt 1: class offsets wrong (victory_point_list at +18 instead of +14)
// attempt 2: offsets fixed, but virtual calls inlined as direct calls (e8) instead of ff 10

class RGE_Victory_Point_Entry;
class RGE_Victory_Entry;

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* victory_list;
    char gap_08[0x08];
    unsigned char victory;
    char gap_11[0x03];
    RGE_Victory_Point_Entry* victory_point_list;

    void check_for_victory();
    virtual void update_victory_point(RGE_Victory_Point_Entry*);
    virtual void update_victory_entry(RGE_Victory_Entry*);

    unsigned char update();
};

class RGE_Victory_Point_Entry {
public:
    char gap_00[0x01];
    unsigned char state;
    char gap_02[0x16];
    RGE_Victory_Point_Entry* next;
};

class RGE_Victory_Entry {
public:
    char gap_00[0x2e];
    unsigned char state;
    char gap_2f[0x01];
    RGE_Victory_Entry* next;
};

unsigned char RGE_Victory_Conditions::update() {
    {
        for (RGE_Victory_Point_Entry* p = victory_point_list; p != 0; p = p->next) {
            if (p->state != 3 && p->state != 1) {
                this->update_victory_point(p);
            }
        }
    }
    {
        for (RGE_Victory_Entry* p = victory_list; p != 0; p = p->next) {
            if (p->state != 3 && p->state != 1) {
                this->update_victory_entry(p);
            }
        }
    }
    check_for_victory();
    return victory;
}
