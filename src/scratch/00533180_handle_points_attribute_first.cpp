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
//   loop forms were unchanged or nonproductive (probes 6-10); broad prologue/register coloring and
//   the loop's out-of-line state-1 block remain unresolved.
// - Best current source is period-plausible typed C++ and retains the proven offsets; no custom flags.

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
    if (entry->state == 0) {
        RGE_Player* player = this->player;
        int val = (int)player->attributes[entry->attribute];
        int points = entry->points;
        RGE_Player** players = player->world->players;
        entry->curr_attribute_amount = (float)val;
        if (val < entry->initial_amount) return;

        val = 0;
        int count = this->player->world->player_num;
        if (0 < count) {
            do {
                if (val != this->player->id &&
                    (float)entry->initial_amount <= (*players)->attributes[entry->attribute]) {
                    entry->state = 1;
                    return;
                }
                val = val + 1;
                players = players + 1;
            } while (val < count);
        }
        this->tot_victory_points += points - entry->curr_points;
        entry->curr_points = points;
        entry->state = 2;
    }
}
