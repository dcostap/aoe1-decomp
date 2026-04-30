// RGE_Victory_Conditions::handle_points_high_attribute_once
// VA: 00533330
// victory.cpp

struct RGE_Game_World {
    char gap_00[0x3C];
    short player_num;         // +0x3C
    void** players;           // +0x40
};

struct RGE_Player {
    char gap_00[0x3C];
    RGE_Game_World* world;    // +0x3C
    char gap_40[0x0A];
    short id;                 // +0x4A
    char gap_4C[4];
    float* attributes;        // +0x50
};

struct RGE_Victory_Point_Entry {
    char gap_00;
    unsigned char state;      // +0x01
    char gap_02[2];
    long attribute;           // +0x04
    long amount;              // +0x08
    long points;              // +0x0C
    long curr_points;         // +0x10
    float curr_attribute_amount; // +0x14
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    RGE_Player* player;       // +0x0C
    char gap_10[0x0C];
    long tot_victory_points;  // +0x1C

    void handle_points_high_attribute_once(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_high_attribute_once(RGE_Victory_Point_Entry* entry) {
    if (entry->state != 0) return;

    long val = (long)this->player->attributes[entry->attribute];
    if (entry->curr_attribute_amount < (float)val) {
        entry->curr_attribute_amount = (float)val;
    }

    RGE_Player* self = this->player;
    int num = self->world->player_num;
    short self_id = self->id;

    for (int i = 1; i < num; i++) {
        RGE_Player* p = (RGE_Player*)self->world->players[i];
        if (i != self_id && (float)entry->amount <= p->attributes[entry->attribute]) {
            entry->amount = (long)p->attributes[entry->attribute];
        }
        self = this->player;
    }

    long result;
    if (entry->curr_attribute_amount < (float)entry->amount) {
        result = (val == entry->amount) ? entry->curr_points : 0;
    } else {
        result = entry->points;
    }

    if (result != entry->curr_points) {
        this->tot_victory_points += result - entry->curr_points;
        entry->curr_points = result;
    }
}
