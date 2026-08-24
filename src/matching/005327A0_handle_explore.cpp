// RGE_Victory_Conditions::handle_explore
// VA: 005327A0
// victory.cpp
//
// Attempt log:
// - baseline: typed RGE_Player fields (visible +0x38, world +0x3C, id +0x4A,
//   relations +0x84, allied_victory +0x104), thiscall percentExplored(), FPU
//   compare `(float)count <= explored * 100.0f` -> 123 diff; FPU operand order
//   wrong (VC5 evaluates the compare left operand last, so source must be
//   `explored * 100.0f >= (float)count`).
// - swapped FPU compare -> size 224 exact, 100% block coverage; only remaining
//   drift was the `cmp byte [relations+id],0` SIB encoding ([edx+ebp] vs orig
//   [ebp+edx]) plus the loop-setup register/lea placement.
// - named p local hoists players[i] above the relations[i] check (worse);
//   pointer-arith, *pp-walker-from-num (breaks setup), pp-inside-loop (SIB
//   reverts), do-while (breaks else-path layout) all regress.
// - best (kept): explicit `RGE_Player** pp = players + i;` before the while
//   with pp-- at the bottom -> diff 10 (4.46%); remaining gap is ONLY the
//   loop setup: rebuilt `mov eax,[eax+40h]; dec esi; lea edi; js` vs original
//   `mov ecx,[eax+40h]; dec esi; js; lea edi,[ecx+esi*4]` (players in ecx and
//   walker init after the entry check). SIB [ebp+edx] correct in this form.
// - left in scratch: 10-byte loop-setup drift; next lead is a source shape
//   that keeps the explicit walker (for the [ebp+edx] SIB) while initializing
//   it in the loop preheader after the entry check (players in ecx).
// - Explicit negative-return probe: delay `players + i` until after an ordinary
//   signed-count early return while retaining the close while-loop topology.
// - Main-agent audit restored canonical polymorphic world/player/victory
//   ownership; exact bytes were revalidated after promotion.

#ifndef VICTORY_CONTEXT_H
class RGE_Visible_Map {
public:
    float percentExplored();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;      // +0x3C
    char gap_3E[0x02];
    class RGE_Player** players;  // +0x40
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x34];
    RGE_Visible_Map* visible;      // +0x38
    RGE_Game_World* world;         // +0x3C
    char gap_40[0x0A];
    short id;                      // +0x4A
    char gap_4C[0x38];
    unsigned char* relations;      // +0x84
    char gap_88[0x7C];
    unsigned char allied_victory;  // +0x104
};

class RGE_Victory_Entry {
public:
    char gap_00[0x20];
    long count;              // +0x20
    char gap_24[0x09];
    unsigned char ally_flag; // +0x2D
    unsigned char state;     // +0x2E
};

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    char gap_04[0x08];
    RGE_Player* player;      // +0x0C

    void handle_explore(RGE_Victory_Entry* entry);
};
#endif

void RGE_Victory_Conditions::handle_explore(RGE_Victory_Entry* entry) {
    RGE_Victory_Conditions* self = this;
    if (entry->state != 0) return;

    if (self->player) {
        if (entry->ally_flag != 0 && self->player->allied_victory != 0) {
            RGE_Game_World* world = self->player->world;
            int num = world->player_num;
            RGE_Player** players = world->players;
            int i = num - 1;
            if (i < 0) return;
            RGE_Player** pp = players + i;
            while (i >= 0) {
                if ((self->player->relations[i] == 0 &&
                     (*pp)->relations[self->player->id] == 0 &&
                     (*pp)->allied_victory != 0) || i == self->player->id) {
                    float explored = (*pp)->visible->percentExplored();
                    if (explored * 100.0f >= (float)entry->count) {
                        entry->state = 2;
                        return;
                    }
                }
                i--;
                pp--;
            }
        } else {
            float explored = self->player->visible->percentExplored();
            if (explored * 100.0f >= (float)entry->count) {
                entry->state = 2;
            }
        }
    }
}
