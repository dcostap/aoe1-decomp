// RGE_Victory_Conditions::handle_points_high_attribute_amount
// VA: 00533410
// victory.cpp:1489-1507
//
// BINARY NOTE: CodeView names the parameter `node` and the long local `amount`.
// It proves the point-entry fields and owner offsets +0x0C, +0x1C, and +0x50.
// The PDB also marks this method protected and proves the four virtual slots.
// Exact recovery required the narrow PDB-backed class context below.
// The broad shared context kept a four-byte EAX/ECX recolor.
// A separate result local and reversed local type order both stayed exact.
// Unused world, entry, and method surfaces were also incidental.
// The retained surface is the smallest tested canonical context.

#ifndef VICTORY_CONTEXT_H
struct RGE_Victory_Entry;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes; // +0x50
};

struct RGE_Victory_Point_Entry {
public:
    unsigned char command;
    unsigned char state;
    unsigned char id;
    unsigned char group;
    long attribute;
    long amount;
    long points;
    long curr_points;
    float curr_attribute_amount;
    RGE_Victory_Point_Entry* next;
};

class RGE_Victory_Conditions {
protected:
    RGE_Victory_Entry* victory_list;
    long list_num;
    RGE_Player* player;
    unsigned char victory;
    char gap_11[3];
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num;
    long tot_victory_points;

    virtual void handle_point_condition(RGE_Victory_Point_Entry* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    void handle_points_high_attribute_amount(RGE_Victory_Point_Entry* node);
    virtual char* condition_description(RGE_Victory_Entry* entry);

public:
    virtual void save(int handle);
};
#endif

void RGE_Victory_Conditions::handle_points_high_attribute_amount(RGE_Victory_Point_Entry* node) {
    if (node->state == 0) {
        long amount = (long)this->player->attributes[node->attribute];
        if (node->curr_attribute_amount < (float)amount) {
            node->curr_attribute_amount = (float)amount;
        }

        amount = (long)(node->curr_attribute_amount / (float)node->amount) * node->points;
        if (amount != node->curr_points) {
            this->tot_victory_points += amount - node->curr_points;
            node->curr_points = amount;
        }
    }
}
