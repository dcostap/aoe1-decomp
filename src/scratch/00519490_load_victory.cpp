// attempt log:
// first pass: EH-framed factory helper with a direct 0x20 new and the observed push order into the victory ctor
// second pass: use a local pointer with an explicit zero path so the failure case stays visible without changing the ctor push order
// third pass: the ctor push order is right, but the zero-path tail still drifts into a different register/branch basin than the packet
// target shape: allocate TRIBE_Victory_Conditions(0x20), call ctor with (this, param1, param2, param3), store result at +0x34 or 0 on alloc fail
// 2026-05-09 GraniteCub: tried 18 focused variants: direct assignment/local,
// explicit if/goto/common-store forms, two-stage result, param locals, this alias,
// assignment-in-if/comma/volatile local, int temp for param3, void*/int victory member,
// ctor p3/p2 declaration probes, visible vptr surface, and brief /O1+/GX. Same EH
// new-expression blocker as 00471C90 and neighboring init helpers: direct new keeps
// exact EH/new/ctor family but sinks store into success path; artificial
// `if (v == 0) v = 0;` reaches closer common-store basin but inserts redundant
// post-merge test/sete code before store. Left cleaner direct-new source.
// No inline asm/hacks.
class RGE_Player;
class TRIBE_Victory_Conditions;

class TRIBE_Player {
public:
    char gap_00[0x34];
    TRIBE_Victory_Conditions* victory;

    void load_victory(int param_1, long* param_2, unsigned char param_3);
};

class TRIBE_Victory_Conditions {
public:
    char pad_0[0x20];
    TRIBE_Victory_Conditions(RGE_Player* player, int param_1, long* param_2, unsigned char param_3);
};

void TRIBE_Player::load_victory(int param_1, long* param_2, unsigned char param_3) {
    TRIBE_Victory_Conditions* v;
    v = new TRIBE_Victory_Conditions((RGE_Player*)this, param_1, param_2, param_3);
    this->victory = v;
}
