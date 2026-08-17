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
// - Fresh worker pass: exact-sibling player/entry aliases regressed to diff 216 and were
//   restored. A narrow volatile id local is binary-supported by the observed stack reload;
//   it forced the 0x10 frame and improved diagnostic diff to 132 with 87.65% shape, but
//   changed the early register colors and made the function one byte too long. Named player,
//   named attribute, self-alias, address-taken nonvolatile id, and while/preheader variants
//   were neutral, duplicate, or worse (diff 139-219). Restored the clean scalar candidate.
// - Pause lead: the remaining blocker is source/register allocation for the original id and
//   current stack homes. Calls, relocation identity, and CFG counts are aligned.
// - Follow-up worker: direct repeated player-id access and direct player->world access,
//   both matching exact victory.cpp sibling idioms, were codegen-neutral. A preheader plus
//   tail pointer increment and a for-loop increment clause regressed structural parity
//   (diff 191/190); an isolated player local reproduced the prior diff-216 basin. Restored
//   the clean scalar candidate. No new natural structural lead remains in these axes.
// - tu-victory-533240 probe: kept a typed player owner only after the point-entry update, so the
//   same owner feeds world and id in the sibling-backed loop. VC5 emitted the unchanged 221-byte,
//   139-byte-diff group; the original 0x10 local window and four stack homes remain unresolved.
// - Short player-id local, threshold-fail no-op, scoped player-count declaration, and split
//   best declaration probes were tested. The short and no-op forms regressed structure;
//   the scoped-count and split-best forms were codegen duplicates. Restored the clean scalar
//   source; the original four-slot local window remains the blocker.
// - Shard E follow-up: period-plausible long locals were codegen-neutral; delayed best
//   assignment regressed diff 153. Nested non-greater control flow, function-scope loop/value
//   declarations, and an inner current initializer were duplicate or neutral. Restored the
//   validated natural scalar source. No new structural lead; the original id spill and frame
//   remain unresolved.
// - Reassessment: direct player/world ownership, a distinct points local, exact-sibling
//   non-polymorphic player/world declarations, and function-scope owner declarations were
//   duplicate codegen. A bottom-increment cursor reproduced the older diff-191 basin.
//   The original parameter-home best, four-slot frame, and spilled id remain unresolved.
// - Canonical-structure follow-up: direct this->player->world/id ownership was codegen-neutral;
//   reversing the equivalent loop condition changed only branch bytes. Initializing the cursor
//   as world->players + 1, and split base/cursor locals, regressed to 175/178-byte differences;
//   a persistent dual cursor reproduced the prior 191-byte basin. Restored the clean scalar
//   do/while source. Target pointer base/cursor colors and spilled id remain open.
// - Revisit pass: natural while, preheader-plus-do/while, single-cursor, and dual-cursor
//   update forms reproduced the known 191/178-byte basins. A short id widened the drift to
//   181 bytes. A 32-variant natural declaration/order lab produced only the existing 221-byte
//   groups; no variant had the target 0x10 frame or 230-byte size. Restored the clean scalar
//   source. The unresolved evidence remains the target's separate player-array base/cursor
//   registers and spilled player id.

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
        RGE_Player* player = this->player;
        RGE_Game_World* world = player->world;
        RGE_Player** players = world->players;
        if (val < entry->initial_amount) {
            best = 0;
        } else {
            num = world->player_num;
            int i = 1;
            if (1 < num) {
                int my_id = player->id;
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
