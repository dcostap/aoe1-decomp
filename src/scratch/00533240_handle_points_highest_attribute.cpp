// RGE_Victory_Conditions::handle_points_highest_attribute
// VA: 00533240
// victory.cpp

struct RGE_Victory_Point_Entry {
    unsigned char command;     // +0x00
    unsigned char state;       // +0x01
    char gap_02[2];
    long attribute;            // +0x04
    long initial_amount;       // +0x08
    long points;               // +0x0C
    long curr_points;          // +0x10
    float curr_attribute_amount; // +0x14
};

struct RGE_Victory_Conditions {
    void* vftable;            // +0x00
    void* victory_list;       // +0x04
    long list_num;            // +0x08
    void* player;             // +0x0C
    unsigned char victory;    // +0x10
    char gap_11[3];
    void* victory_point_list; // +0x14
    long point_list_num;      // +0x18
    long tot_victory_points;  // +0x1C

    void handle_points_highest_attribute(struct RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_highest_attribute(RGE_Victory_Point_Entry* entry) {
    if (entry->state) return;

    long val = (long)*(float*)(*(long*)((char*)(this->player) + 0x50) + entry->attribute * 4);
    entry->curr_attribute_amount = (float)val;

    if (val < entry->initial_amount) {
        // Find highest among all players
        void* world = *(void**)((char*)(this->player) + 0x3C);
        short num = *(short*)((char*)world + 0x3C);
        void** players = *(void***)((char*)world + 0x40);
        short my_id = *(short*)((char*)(this->player) + 0x4A);
        float curr_best = 0.0f;

        for (long i = 1; i < (long)num; i++) {
            if (i == (long)my_id) continue;

            float other_val = *(float*)(*(long*)((char*)players[i] + 0x50) + entry->attribute * 4);
            
            if (other_val > curr_best) {
                curr_best = other_val;
            }
        }

        long new_val = (long)curr_best;
        if (new_val != entry->curr_points) {
            this->tot_victory_points += new_val - entry->curr_points;
            entry->curr_points = new_val;
        }
    }
}
