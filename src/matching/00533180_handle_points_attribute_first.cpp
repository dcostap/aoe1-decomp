// RGE_Victory_Conditions::handle_points_attribute_first
// VA: 00533180
// victory.cpp
// Attempt log:
// - Baseline behavior: when state is zero, truncate the current player's attribute, record it,
//   require the initial amount, scan the other players for an equal-or-higher value, then either
//   set state 1 or award the points delta and set state 2.
// - Typed RGE_Player/RGE_Game_World ownership improved the source model without changing size;
//   direct entry->attribute indexing recovered the compiler's shl/address family (probe 4).
// - Reversed the threshold to the binary-observed negative early-return compare (probe 5),
//   recovering 70% exact-block coverage and the 188-byte best reconstruction.
// - Explicit goto/cold-tail, register-qualified owner/entry aliases, and equivalent continue/else
//   loop forms were unchanged or nonproductive (prior probes 6-10).
// - A nested self-id/threshold dispatch with duplicated natural loop-advance statements (probe 8
//   of the current pass) recovered the cold state-1 block, exact size, and the original ESI/EDI
//   coloring; current validation is byte-exact. The duplicated advances are ordinary source control
//   flow, not compiler-only scaffolding, and all field offsets remain binary-proven; no custom flags.

class RGE_Game_World;

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[4];
    float* attributes;
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Victory_Point_Entry {
public:
    unsigned char command; unsigned char state; char gap_02[2];
    long attribute; long initial_amount; long points; long curr_points;
    float curr_attribute_amount;
};
class RGE_Victory_Conditions {
public:
    void* vftable; void* victory_list; long list_num; RGE_Player* player;
    unsigned char victory; char gap_11[3]; void* victory_point_list;
    long point_list_num; long tot_victory_points;
    void handle_points_attribute_first(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_attribute_first(RGE_Victory_Point_Entry* entry) {
    RGE_Player* player;
    RGE_Victory_Point_Entry* p;
    if (entry->state == 0) {
        player = this->player;
        p = entry;
        int val = (int)player->attributes[p->attribute];
        int points = p->points;
        RGE_Player** players = player->world->players;
        p->curr_attribute_amount = (float)val;
        if (val < p->initial_amount) return;

        val = 0;
        int count = this->player->world->player_num;
        if (0 < count) {
            do {
                if (val == this->player->id) {
                    val = val + 1;
                    players = players + 1;
                } else if ((float)p->initial_amount > (*players)->attributes[p->attribute]) {
                    val = val + 1;
                    players = players + 1;
                } else {
                    p->state = 1;
                    return;
                }
            } while (val < count);
        }
        this->tot_victory_points += points - p->curr_points;
        p->curr_points = points;
        p->state = 2;
    }
}
