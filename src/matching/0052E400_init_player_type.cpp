// VA: 0052E400 TRIBE_World::init_player_type
// PDB source: tworld.cpp
// Attempt log:
// natural /GX new-expression for TRIBE_Master_Player, base fallback, virtual setup slot +4: correct EH/new/ctor/body skeleton.
// fixed base as polymorphic so base call uses complete this, and rebased fields so field_30/+38/players +48 match.
// tried allocated class size 0x2C via implicit vptr+0x28 payload; operator new size correct.
// tried condition spellings: type!=1, (type&0xff)!=1, int temp, unsigned temp with &=0xff/--temp. Best keeps 180B but hoists type load before FS registration and uses a different top compare/push family.
// tried /Ob0 (no help) and /O1 (too short); kept /GX because original has EH frame.
// left in scratch: body after branch is largely understood, but remaining mismatch is broad early EH/parameter scheduling and fallback push order, not accepted drift.
// Retry 2026-05-26 Boss pass: 15 probes on VA 0052E400 only. Revalidated baseline /GX: 180B, 73.8889% positional / 38.8889% edit, first mismatch +14 from type load before FS registration. Tried direct `type != 1`, `type == 1` else, unsigned-char temp, int temp with decrement, mutating `type`, saving `player` before/after branch, direct `p->init`, index local, manual placement-new (VC5 rejected), expression forms `((t&0xff)-1)==0` / `!=0`, no-temp casts, and flags /Ob0 /G5 /Oa /Oy- /O1 with /GX. Kept the int-temp/decrement variant because it improves to 67.7778% positional / 25.0000% edit and first mismatch +35, but it still has an extra `and eax,0xff` and shifts the allocation branch. GIVEUP: not accepted_drift quality; remaining drift is broad EH/type-test/fallback layout and shifted new/virtual-call path, not localized equivalent drift.
// Luna52E400 session: baseline rebuilt 185B, 147 differing bytes, first mismatch +35 from a duplicate `and eax,0xff`; all four calls and body CFG aligned.
// Tested direct type guards, unsigned/int/byte temporary variants, promoted `type - 1`, and explicit mask forms; the closest unchanged basin is the int temporary with one explicit byte cast.
// Tested the canonical RGE_Master_Player/TRIBE_Master_Player inheritance and finish_init(void*) surface; emitted metrics stayed in the same 185B basin, so it is retained for source plausibility.
// Tested condition arm inversion and found it changes branch layout/call ordering; restored the clean source after each nonproductive probe.
// Session exhausted at 10 meaningful hypotheses; remaining gap is localized to VC5 type-test/EH scheduling, not behavior or call/layout uncertainty.
// Main-agent source audit: removed the redundant `t = (unsigned char)t` compiler-
// steering assignment from the retained candidate. The parameter already has the
// proven unsigned-byte ABI, so the ordinary promoted temporary is the defensible
// source even though it returns to the broader early-load codegen basin. Validation:
// 181/180 bytes, 150 strict differing bytes, 98.31% shape, 4/4 calls aligned;
// first mismatch +0x0E from loading `type` before FS registration.
// Luna52E400b sequential pass: full RGE world/Player virtual surfaces and inherited
// field ownership, switch CFG, self alias, and volatile dword parameter-view probes
// were nonproductive; the full context/switch/alias forms were codegen-neutral and
// the volatile view regressed size/coverage. A guarded variant lab (8 source forms,
// plus VC5-small flag classification) found no exact or invariant-eligible variant;
// restored the prior clean canonical source. Remaining lead is VC5 EH/type-test
// scheduling at +0x0E, with body/calls/layout aligned and no behavioral blocker.
// orch-luna-52e400-w1: direct switch(type) with case 1 and a shared success return
// reproduces the original dec/je dispatch and exact 180-byte output; switching a
// decremented temporary was codegen-equivalent but hoisted the type load.

class RGE_Game_World {
public:
    virtual void v0();
    unsigned char init_player_type(int player, short index, unsigned char type);
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void finish_init(int player, void* a, void* b);
    char bytes[0x28];
    RGE_Master_Player(int player);
};

class TRIBE_Master_Player : public RGE_Master_Player {
public:
    TRIBE_Master_Player(int player);
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_04[0x2C];
    void* field_30;
    char gap_34[4];
    void* field_38;
    char gap_3C[0x0C];
    TRIBE_Master_Player** players; // +0x48

    virtual unsigned char init_player_type(int player, short index, unsigned char type);
};

unsigned char TRIBE_World::init_player_type(int player, short index, unsigned char type)
{
    switch (type) {
    case 1: {
        TRIBE_Master_Player* p = new TRIBE_Master_Player(player);
        this->players[index] = p;
        this->players[index]->finish_init(player, this->field_38, this->field_30);
        break;
    }
    default:
        return RGE_Game_World::init_player_type(player, index, type);
    }

    return 1;
}
