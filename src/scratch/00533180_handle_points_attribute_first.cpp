// RGE_Victory_Conditions::handle_points_attribute_first
// VA: 00533180
// victory.cpp
// Give-up notes (10+ honest tries):
// - Baseline behavior understood: if entry state is 0, ftol current player attr, store curr_attribute_amount,
//   gate on initial_amount, scan other players for same/higher attribute, mark state 1 if any; otherwise award
//   points delta and mark state 2.
// - Tried natural typed RGE_Player/RGE_World surface, raw-offset/minimal surface, top-declared locals,
//   delayed/repeated entry->attribute expressions, goto state1 tail, register/volatile parameter probes,
//   and flags /O1, /Od, /Ox, /Gf, /Ob0, /Og, /Oi-.
// - Best current source has correct size (186 B) and behavior, but broad register/topology drift remains:
//   rebuilt preloads param into ESI before `push edi` and uses EDI/EBX differently, while original pushes all
//   callee-saves first, keeps entry in EDI, this in EBP, current player in ESI, and attr offset in EBX.
// - Also current loop emits a jge+jmp backedge/tail layout family in some variants; source-goto tail improves
//   semantic layout but does not fix the early register basin. Not an accepted_drift proposal: drift is broad.

class RGE_Victory_Point_Entry {
public:
    unsigned char command; unsigned char state; char gap_02[2];
    long attribute; long initial_amount; long points; long curr_points;
    float curr_attribute_amount;
};
class RGE_Victory_Conditions {
public:
    void* vftable; void* victory_list; long list_num; void* player;
    unsigned char victory; char gap_11[3]; void* victory_point_list;
    long point_list_num; long tot_victory_points;
    void handle_points_attribute_first(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_attribute_first(RGE_Victory_Point_Entry* entry) {
    if (entry->state) return;

    void* player = this->player;
    void* world;
    void** players;
    int i;
    int count;
    int my_id;
    long val;
    long points;
    long amount;
    int attr;

    attr = entry->attribute;
    val = (long)*(float*)(*(long*)((char*)player + 0x50) + attr * 4);
    points = entry->points;
    world = *(void**)((char*)player + 0x3C);
    entry->curr_attribute_amount = (float)val;
    amount = entry->initial_amount;
    players = *(void***)((char*)world + 0x40);
    if (val < amount) return;

    player = this->player;
    i = 0;
    count = *(short*)((char*)*(void**)((char*)player + 0x3C) + 0x3C);
    if (count > 0) {
        my_id = *(short*)((char*)player + 0x4A);
        do {
            if (i != my_id) {
                void* other = *players;
                if ((float)amount <= *(float*)(*(long*)((char*)other + 0x50) + attr * 4)) {
                    goto other_player;
                }
            }
            i++;
            players++;
        } while (i < count);
    }

    this->tot_victory_points += points - entry->curr_points;
    entry->curr_points = points;
    entry->state = 2;
    return;

other_player:
    entry->state = 1;
}
