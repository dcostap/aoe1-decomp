// RGE_Victory_Conditions::handle_points_highest_attribute
// VA: 00533240
// victory.cpp
// Attempt log:
// - Baseline: reconstructed from scratch (previous scratch source was a decompiler-shaped
//   wrong reconstruction: reversed threshold direction, invented max-scan loop, invented
//   trailing ftol). Modeled on exact sibling handle_points_attribute_first (00533180):
//   same RGE_Player/RGE_Game_World/RGE_Victory_Point_Entry/RGE_Victory_Conditions surface.
// - Binary semantics: val = ftol(player->attributes[entry->attribute]); curr_amount =
//   (float)val; best starts at entry->points; if val < entry->initial_amount then best = 0
//   else scan players[1..num-1]: if any other player's attribute > curr_amount -> best = 0
//   (break), if == curr_amount -> best = entry->curr_points; finally if best != curr_points
//   award delta to tot_victory_points and store best.
// - Probe 3 changed the indexed for-loop to a guarded do/while with direct repeated attribute
//   reads; size gap fell from 36 to 18 bytes and the FPU compare family moved closer.
// - Probe 4 restored the binary `other > curr_amount` operand order and branch-local id; shape
//   improved to 63.22% with the expected fcomp/test-ah-41 sequence.
// - Probe 5 named the proven attribute offset and world owner; best emitted reconstruction was
//   197 differing bytes, 69.14% shape, but frame stayed 0xC versus the original 0x10.
// - Probes 6-12 tested same-TU aliases, register hints, a split cursor, short id width, a self
//   alias, and a points-field pointer. They were duplicate, neutral, or worse; no ABI/call/CFG
//   defect was found. Left in scratch: structural/register allocation gap (original spills this,
//   curr_amount, id, and count; best rebuild spills only this/attribute-related temporaries).
// - Main-agent audit restored polymorphic player/world/victory ownership;
//   emitted code is unchanged.

class RGE_Game_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[4];
    float* attributes;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
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
    virtual ~RGE_Victory_Conditions();
    void* victory_list; long list_num; RGE_Player* player;
    unsigned char victory; char gap_11[3]; void* victory_point_list;
    long point_list_num; long tot_victory_points;
    void handle_points_highest_attribute(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_highest_attribute(RGE_Victory_Point_Entry* entry) {
    RGE_Player* player;
    if (entry->state == 0) {
        player = this->player;
        long attribute = entry->attribute;
        long val = (long)player->attributes[attribute];
        long best = entry->points;
        float curr_amount = (float)val;
        entry->curr_attribute_amount = curr_amount;
        RGE_Game_World* world = player->world;
        RGE_Player** players = world->players;
        if (val < entry->initial_amount) {
            best = 0;
        } else {
            int num = world->player_num;
            int i = 1;
            if (1 < num) {
                int my_id = player->id;
                do {
                    ++players;
                    if (i != my_id) {
                        if ((*players)->attributes[attribute] > curr_amount) {
                            best = 0;
                            break;
                        }
                        if ((*players)->attributes[attribute] == curr_amount) {
                            best = entry->curr_points;
                        }
                    }
                    ++i;
                } while (i < num);
            }
        }
        if (best != entry->curr_points) {
            this->tot_victory_points += best - entry->curr_points;
            entry->curr_points = best;
        }
    }
}
