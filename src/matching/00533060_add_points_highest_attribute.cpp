#ifndef VICTORY_CONTEXT_H
struct RGE_Victory_Point_Entry {
    unsigned char command;
    char gap_01[3];
    long attribute;
    long amount;
    long points;
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Point_Entry* add_point(unsigned char p1, unsigned char p2);
    unsigned char add_points_highest_attribute(unsigned char p1, unsigned char p2, long attribute, long amount, long points);
};
#endif

unsigned char RGE_Victory_Conditions::add_points_highest_attribute(unsigned char p1, unsigned char p2, long attribute, long amount, long points) {
    RGE_Victory_Point_Entry* entry = this->add_point(p2, p1);
    if (entry != 0) {
        entry->attribute = attribute;
        entry->command = 2;
        entry->amount = amount;
        entry->points = points;
        return 1;
    }
    return 0;
}
