// RGE_Victory_Conditions::handle_attribute
// VA: 005326F0
// victory.cpp
// Attempt log:
// Probe 1: existing natural source broad mismatch; no stack local, wrong FPU compare tail.
// Probe 2: volatile scaled index/player local worsened register allocation.
// Probe 3: self alias + plain scaled local still ESI player / EBX attr.
// Probe 4: entry alias first, player second, direct member-style accesses; got ESI player/EDI entry.
// Probe 5: declaration order no change.
// Probe 6: no entry alias, direct parameter uses, player local; still ESI player.
// Probe 7: initialized scaled local before player load; no codegen change.
// Probe 8: /Ob0 no change; /O1 too small (158B), removed flag.
// Probe 9: typed RGE_Player/RGE_World surface restored original prologue/push-ecx/EDI player; entry still ECX.
// Probe 10: explicit entry alias with typed surface; prologue exact, but entry ECX / loop EDX instead of entry ESI / loop ECX.
// Probe 11: register-qualified entry alias no change.
// Probe 12: delay entry alias assignment until after null guard no change.
// Probe 13: flip final compare spelling to total >= count restored original FPU compare tail.
// Probe 14: register-qualified loop index; no codegen change.
// ACCEPTED_DRIFT 2026-05-21 (Boss approved): remaining mismatch is register allocation/addressing only after exact prologue/epilogue/branches/FPU compare tail. Rebuilt uses ECX for entry and EDX for loop index where original uses ESI for entry and ECX for loop index, plus equivalent relation/attribute address encodings. Behavior, stack cleanup, memory effects, and final state stores match.

class RGE_Victory_Entry { public: char gap_00[0x1C]; long number; long count; char gap_24[0x09]; unsigned char ally_flag; unsigned char state; };
class RGE_World { public: char gap_00[0x3C]; short player_num; char gap_3E[2]; void** players; };
class RGE_Player { public: char gap_00[0x3C]; RGE_World* world; char gap_40[0x0A]; short id; char gap_4C[4]; float* attributes; char gap_54[0x30]; unsigned char* relations; char gap_88[0x7C]; unsigned char allied_victory; };
class RGE_Victory_Conditions { public: char gap_00[0x0C]; RGE_Player* player; void handle_attribute(RGE_Victory_Entry* entry); };

void RGE_Victory_Conditions::handle_attribute(RGE_Victory_Entry* entry)
{
    RGE_Player* p = this->player;
    RGE_Victory_Entry* e;
    int attr_idx_scaled;
    float total;

    if (p == 0)
        return;

    e = entry;
    attr_idx_scaled = e->number << 2;
    total = *(float*)((char*)p->attributes + attr_idx_scaled);

    if (e->ally_flag && p->allied_victory) {
        RGE_World* world = p->world;
        register int i = world->player_num - 1;
        if (i >= 0) {
            void** pp = world->players + i;
            do {
                if (p->relations[i] == 0) {
                    RGE_Player* other = (RGE_Player*)*pp;
                    int my_id = p->id;
                    if (other->relations[my_id] == 0 && i != my_id && other->allied_victory) {
                        total += *(float*)((char*)other->attributes + attr_idx_scaled);
                    }
                }
                --i;
                --pp;
            } while (i >= 0);
        }
    }

    if (total >= (float)e->count)
        e->state = 2;
    else
        e->state = 0;
}
