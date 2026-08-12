// VA: 0050A510
// PDB: tcommand.cpp lines 708-770
// TRIBE_Command::do_command_give_attribute
// FLAGS: default

// Attempt log:
// v1: Simple struct casts + __stdcall function pointers through vtable.
//     Result: 320 bytes (69 short). No ecx setup for __thiscall virtuals.
// v2: RGE_Player_VTable + RGE_Base_Game_VTable with VPAD padding for correct
//     vtable offsets (0x78, 0x40, 0xE8). Virtual member function calls.
//     Result: 336 bytes (53 short). Partial ecx setup, but early this->world read
//     consumes ecx and prevents edi = this pattern.
// v3: As v2 but with gworld = this->world cached. 352 bytes.
// v4: Scoped blocks, each reading this->world->players fresh. 368 bytes (best so far).
// v5: Full RGE_Player data members to match sizeof. 368 bytes.
// v6: Variant lab (direct/world_local/this_local caching patterns). All 368 bytes.
//     G0001 (world_local) has edit_diff=316 (smallest).
// v7: Non-virtual wrapper dispatch. Adds CALL/RET overhead.
// v8: DAT_00576574 comparison constant. 368 bytes.
// v9: Double comparison (v > 0.0). 368 bytes.
// v10: Inline cost=0 inside if-else. BreakS fld/fcom order differently.
//
// Remaining gap: 368 bytes vs 389 (21 bytes short).
// This pass used the positive float guard and fresh typed world-player
// expressions, aligning all eight calls and reaching a 290-byte strict diff;
// shared command/player ABI normalization was neutral. The remaining gap is
// broad frame/register/FPU scheduling, not an accepted-drift-sized hunk.
// Main-agent audit removed inline empty virtual definitions and restored
// canonical polymorphic world/player/base-game ownership.
// Session 2026-08-12: a local attr_id used only for the lookup was codegen-neutral;
// reusing it through the transfer calls worsened the frame and was rolled back.
// The generated add_attribute_num(short, float, unsigned char) player ABI moved
// the first mismatch from +0x53 to +0x63 and reduced strict drift to 202 bytes.
// The generated RGE_Command and RGE_Base_Game virtual declarations were neutral.
// Reversing cost-plus-value and materializing a total were neutral or worse;
// the natural `v + cost` source remains authoritative.
//
// Prologue: rebuilt uses `sub esp,0Ch` (3 bytes) + saves `this` to stack slot
// at [esp+18h] (3 bytes). Original uses `push ecx` (1 byte, allocates 4B local
// space) + `mov edi, ecx` (2 bytes, saves this to edi). The 12B sub allocation
// provides 3 dwords: cost, world-save, v. Original only needs 2: cost and v
// (param_1 slot reused). Extra slot from world/this save = +8B frame + extra
// instructions.
//
// Virtual function dispatch adds register pressure: VC5 caches vtable function
// pointers in ebp/ebx between calls (for calls 1-4 which all share vt[0x1E]).
// Original uses `call [eax+78h]` (3 bytes, no caching). Virtual dispatch uses
// `mov ebp, [ecx+78h]; ...; call ebp` (5+ bytes, caches pointer). This extra
// register usage forces world/this to stack instead of edi.
//
// Core challenge: cannot express inline vtable dispatch (`call [eax+78h]`) in
// pure C++ without inline asm. Virtual member functions always read+save the
// function pointer. This shifts register allocation enough to prevent matching
// the original 389-byte layout.

#include <windows.h>
#include <cstdlib>

struct TRIBE_Command_Give_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char to_player_id;
    unsigned char attr_id;
    float attr_amount;
    float attr_cost;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x3C];
    class RGE_Player** players;
};

#define VPAD(n) virtual void v##n();

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes;

    VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29)
    virtual void add_attribute_num(short id, float v, unsigned char z) = 0;
    VPAD(31) VPAD(32) VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38)
    VPAD(39) VPAD(40) VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46)
    VPAD(47) VPAD(48) VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54)
    VPAD(55) VPAD(56) VPAD(57)
    virtual void sendEvent(int a, int b, int c, int d, int e) = 0;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    virtual void notification(int command, long player_id, long to_player_id,
                              long attr_id, long amount);
};

extern RGE_Base_Game* rge_base_game;
extern float DAT_00576574;
extern double DAT_00576578;
extern long __ftol(float);

class TCommunications_Handler;

class RGE_Command {
public:
    virtual void do_command_give_attribute(TRIBE_Command_Give_Attribute* ca) = 0;
    virtual ~RGE_Command();
    virtual void do_command(void* command) = 0;
    virtual void command_give_attribute(int player_id, int attr_id,
                                        int value, float amount) = 0;

    RGE_Game_World* world;
    void* last_order;
    int last_order_size;
    unsigned int last_order_time;
    TCommunications_Handler* com_hand;
};

class TRIBE_Command : public RGE_Command {
public:

    virtual void do_command_give_attribute(TRIBE_Command_Give_Attribute* ca);
};

void TRIBE_Command::do_command_give_attribute(TRIBE_Command_Give_Attribute* ca)
{
    float v;
    float cost;
    
    cost = 0.0f;
    if (ca->attr_amount >= 0.0f) {
        v = ca->attr_amount;
    } else {
        v = 0.0f;
    }
    
    if (v > 0.0) {
        cost = ca->attr_cost * v;
    }
    
    {
        float* attr_ptr = &this->world->players[ca->player_id]->attributes[ca->attr_id];
        
        if (v + cost > *attr_ptr) {
            cost = *attr_ptr * ca->attr_cost;
            v = *attr_ptr - cost;
        }
    }
    
    this->world->players[ca->to_player_id]->add_attribute_num(ca->attr_id, v, 0);
    this->world->players[ca->player_id]->add_attribute_num(ca->attr_id, -(v + cost), 0);
    this->world->players[ca->player_id]->add_attribute_num(0x35, v, 0);
    this->world->players[ca->to_player_id]->add_attribute_num(0x35, -(v + cost), 0);
    
    {
        rge_base_game->notification(7, ca->player_id, ca->to_player_id,
                                    ca->attr_id, (long)v);
    }
    
    this->world->players[ca->to_player_id]->sendEvent(
        ca->player_id, ca->to_player_id, 0x20A, ca->attr_id, (long)ca->attr_amount);
}
