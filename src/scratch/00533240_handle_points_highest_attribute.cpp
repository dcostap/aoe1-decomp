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
// - Constructor/TU context probe: the recovered four-slot victory surface,
//   polymorphic world/player surfaces, and named point-entry id/group fields
//   are canonical but emitted the same structural candidate. The remaining
//   blocker is the original four-dword local window versus the natural 0xC frame.
// - Fresh pass: an entry alias/int-width spelling was codegen-neutral. A four-dword
//   aggregate with direct attribute expressions improved to diff 141 but added an
//   implausible 0x18 frame; scalar top-level count/current locals improved to
//   diff 139 (75.61% shape, 0xC frame, 22.22% blocks). A self alias was
//   codegen-neutral and was removed during main-agent source audit.
// - A preheader cursor plus tail increment regressed to diff 178; decompiler-style
//   top-level declarations regressed to the prior diff 197 basin. Declaration versus
//   assignment initialization of self was neutral. Remaining gap is the original
//   four-dword local/register allocation window; calls and CFG are aligned.

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
    unsigned char command; unsigned char state; unsigned char id; unsigned char group;
    long attribute; long initial_amount; long points; long curr_points;
    float curr_attribute_amount;
};
class RGE_Victory_Conditions {
public:
    virtual void handle_point_condition(void* entry);
    virtual void handle_condition(void* entry);
    virtual char* condition_description(void* entry);
    virtual void save(int handle);
    void* victory_list; long list_num; RGE_Player* player;
    unsigned char victory; char gap_11[3]; void* victory_point_list;
    long point_list_num; long tot_victory_points;
    void handle_points_highest_attribute(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_highest_attribute(RGE_Victory_Point_Entry* entry) {
    int num;
    float current;
    if (entry->state == 0) {
        int val = (int)this->player->attributes[entry->attribute];
        int best = entry->points;
        current = (float)val;
        entry->curr_attribute_amount = current;
        RGE_Game_World* world = this->player->world;
        RGE_Player** players = world->players;
        if (val < entry->initial_amount) {
            best = 0;
        } else {
            num = world->player_num;
            int i = 1;
            if (1 < num) {
                int my_id = this->player->id;
                do {
                    ++players;
                    if (i != my_id) {
                        if ((*players)->attributes[entry->attribute] > current) {
                            best = 0;
                            break;
                        }
                        if ((*players)->attributes[entry->attribute] == current) {
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
