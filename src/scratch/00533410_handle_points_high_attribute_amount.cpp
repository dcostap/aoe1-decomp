// attempt log:
// first pass: natural guard + float/int math for the high-attribute victory point update
// second pass: the table/player and compare shapes are close, but the FPU compare/test mask still lands in the wrong basin
// third pass: try /GX before giving up on the remaining FPU branch drift
// paused here: the only remaining mismatch is the early player/table load order plus the FPU compare mask, and /GX did not move it
// target shape: if state byte is set return; otherwise ftol the resource value, update curr_attribute_amount max, then update curr_points/tot_victory_points when the derived score changes

class RGE_Player_Table;

class RGE_Victory_Point_Entry {
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
public:
    void* vtable_ptr;
    void* victory_list;
    long list_num;
    RGE_Player_Table* player;
    unsigned char victory;
    unsigned char pad_11[3];
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num;
    long tot_victory_points;

    void handle_points_high_attribute_amount(RGE_Victory_Point_Entry* point);
};

class RGE_Player_Table {
public:
    char gap_00[0x50];
    float* resource_table;
};

void RGE_Victory_Conditions::handle_points_high_attribute_amount(RGE_Victory_Point_Entry* point) {
    if (point->state != 0) {
        return;
    }

    RGE_Player_Table* player = this->player;
    float* values = player->resource_table;
    int attribute = point->attribute;
    float current = values[attribute];
    int temp = (int)current;
    if (point->curr_attribute_amount > (float)temp) {
        point->curr_attribute_amount = (float)temp;
    }

    int points = (int)(point->amount / point->curr_attribute_amount) * point->points;
    if (points != point->curr_points) {
        this->tot_victory_points += points - point->curr_points;
        point->curr_points = points;
    }
}
