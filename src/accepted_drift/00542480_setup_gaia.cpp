// VA: 00542480 RGE_Game_World::setup_gaia()
// PDB source: World.cpp lines 1156-1159 (104 bytes, 34 asm lines)
// FLAGS: config/flags/00542480_setup_gaia.rsp uses /GX for original EH new-expression frame.
// No inline asm/hacks.
//
// === ACCEPTED_DRIFT ===
// Same behavior-neutral VC5 no-op phi-merge artifact as accepted World/tworld init helpers:
// first 83 bytes exact, then dead `test eax,eax; jne +0` shifts final epilogue into padding.
//
// Behavior: allocate an RGE_Player (sizeof 0x220), construct it as GAIA with
// (this, *master_players, 0, "GAIA", 0, 1), then store it through *players.
//
// Attempt log:
// - Baseline explicit null normalization matches EH prologue/allocation/ctor args/call/null xor/common-store
//   family but VC5 inserts redundant `test eax,eax; jne +0` at the ctor/null join before loading players.
//   Best result: 104/104 bytes, positional diff 16.3462%, edit diff 7.6923%, 100 equal after resync.
// - Direct `*players = new ...` removes redundant join test but changes to success-path store/null-to-tail family
//   (diff 21.1538%).
// - Assignment-in-condition produced extra boolean/sete plumbing at the join, worse.
// - Hoisting `players` local adds EDI/save and shifts the EH frame; worse.
// - Local-only declarations versus shared include: no effect from baseline.
// - Manual `operator new` + explicit constructor loses VC5 EH new-expression lowering (80-byte text), wrong family.
// - /Ob0 with explicit null normalization: no effect. /O1 /GX: wrong 86-byte family. Removing /GX: wrong 64-byte
//   non-EH family. Restored /GX-only flag.
// - Hoisting `*master_players` into a local adds EDI/save and shifts call setup; worse.
// - Narrow ctor parameter declarations (`char` flags, `char*` name) do not affect the blocker.
// - 2026-05-10 pass on this VA only: retried 15+ variants: direct, if-null/if-not/goto common-store,
//   assignment-in-condition, zero-init, volatile pointer, bool temp, empty-if, if/else member stores, hoisted
//   players/master locals, char ctor flags/name, void* store, comma/no-op forms. No exact. Best remains the
//   current explicit null-normalization/common-store shape: edit diff 7.6923%, positional 16.3462%; mismatch
//   is a redundant join `test eax,eax; jne +0` that shifts the final FS restore and add/ret into padding;
//   accepted under Boss's same-artifact ruling.
// - 2026-05-10 SpruceGlow Boss-assigned pass: revalidated current best and tried 16 variants:
//   direct/local assignment, if-null/if-not, goto common/null, players/master locals, member reference,
//   store-in-both-arms, volatile pointer, bool temp, zero-init, assignment-in-if, and explicit casts.
//   No exact. Direct/local sink store to success path. Common-tail variants keep the redundant join test.
//   Member-reference reduced positional diff to 14 but worsened edit diff and still changes tail layout, so not kept.
// Accepted drift: same null-path/common-store join artifact as sibling World init helpers. Allocation size, EH frame,
// ctor args/call, final store, stack cleanup, and behavior are understood. No inline asm/hacks.

class RGE_Game_World;

class RGE_Player {
public:
    char _gap_00[0x220];
    RGE_Player(RGE_Game_World* world, void* masterPlayerInfo, int isGaia,
               const char* name, int flag, int isActive);
};

class RGE_Game_World {
public:
    char _gap_00[0x40];
    RGE_Player** players;        // +0x40
    char _gap_44[0x04];
    void** master_players;       // +0x48

    void setup_gaia();
};

void RGE_Game_World::setup_gaia() {
    RGE_Player* p = new RGE_Player(this, *master_players, 0, "GAIA", 0, 1);
    if (p == 0) {
        p = 0;
    }
    *players = p;
}
