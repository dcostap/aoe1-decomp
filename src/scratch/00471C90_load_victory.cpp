// 00471C90 RGE_Player::load_victory
// EH-framed allocation helper that stores constructed victory object at +0x34.
// FLAGS: config/flags/00471C90_load_victory.rsp uses /GX for original SEH/new-expression basin.
//
// BLOCKER: same /GX new-expression common-tail scheduling family as 00541C90,
// 00541D00, 0052E5F0, and 00541BC0. Natural direct new emits exact EH prologue,
// allocation size, constructor arg push order, and ctor call, but VC5 sinks the
// member store into the non-null path and sends the null path to a cleanup tail
// after the compared range. Explicit common-store shapes reach the original
// ctor-success jump/null-xor/common store family, but insert a redundant post-join
// `test eax,eax; jne +0`, shifting and truncating the EH epilogue inside the
// 99-byte window.
//
// Attempt log:
// 1. Prior direct new + local temp: VC5 hoisted/sank the store into the success arm.
// 2. Prior placement-new/operator_new shape: wrong TU size/family, not kept.
// 3. 2026-05-09 pass: tried direct assignment, explicit if/goto/common-store forms,
//    two-stage result, param locals, this alias, assignment-in-if/comma/volatile local,
//    no-vptr class surface, void*/int member, ctor p3/p2 declaration probes, and /O1+/GX.
//    Same EH new-expression blocker; direct new keeps exact EH/new/ctor family but sinks
//    store into success path; `if (victory == 0) victory = 0;` reaches closer common-store
//    basin but inserts a redundant post-merge test before store.
// 4. 2026-05-10 pass on this VA only: retried 15+ focused variants with fixed public
//    ctor surface: direct/local new, if-null/if-not/goto common-store, assignment-in-condition,
//    zero-init, volatile local, param3 as int, no-vptr layout, bool temp, empty-if,
//    if/else member stores, and flag probes /O1, /Og, /Ob0, /Ox, /Gf, /Gy, /Oa, /Ot with /GX.
//    No exact.
// 5. Best current source below: edit diff 11.1111%, positional 16.1616%; mismatch is
//    redundant join-test plus epilogue truncation (`83c4` incomplete at tail). Not an
//    accepted_drift suggestion under Boss's window/truncation ruling.
// 6. 2026-05-10 SpruceGlow Boss-assigned pass: revalidated current best and tried 16 variants:
//    direct/local assignment, explicit if-null/if-not null normalization, goto common/null,
//    param1 local, param2 local, param3 int local, member reference/pointer alias,
//    store-in-both-arms, volatile pointer, bool temp, and assignment-in-if. No exact.
//    Direct/local forms sink the store into success path (21 positional/15 edit, first mismatch 50).
//    Common-tail forms all keep the redundant `test eax,eax; jne +0` (16 positional/11 edit,
//    first mismatch 78) and shift/truncate the EH epilogue inside the function window. Store-in-arm
//    variants reduce positional bytes to 14 but have worse edit diff and real branch/store layout drift.
// No inline asm/hacks. No accepted_drift suggestion due the denied EH join-test/window truncation pattern.

void* __cdecl operator new(unsigned int size);

class RGE_Player;

class RGE_Victory_Conditions {
public:
    void* vtable_ptr;
    char pad_04[0x20 - 0x4];

    RGE_Victory_Conditions(RGE_Player* player, int param_1, long* param_2, unsigned char param_3);
};

class RGE_Player {
public:
    char pad_00[0x34];
    RGE_Victory_Conditions* victory_conditions;

    void load_victory(int param_1, long* param_2, unsigned char param_3);
};

void RGE_Player::load_victory(int param_1, long* param_2, unsigned char param_3) {
    RGE_Victory_Conditions* victory;

    victory = new RGE_Victory_Conditions(this, param_1, param_2, param_3);
    if (victory == 0) {
        victory = 0;
    }
    this->victory_conditions = victory;
}
