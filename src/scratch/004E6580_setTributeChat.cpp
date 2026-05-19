// VA: 004E6580 setTributeChat (117B)
// taimdmd.cpp
//
// Attempt log:
// 1. Original scratch behavior right but source evaluated all strategicNumber calls before arithmetic, causing saved ECX/EBP stack-temp basin and broad shifted diff (78.6% pos / 73.5% edit).
// 2. Reordered source to perform rand % strategic(0x7E), then strategic(0x7E)/2, then add strategic(0x7D). This matches the original arithmetic/call interleave and improves to 35.0% pos / 24.8% edit, but VC5 keeps `this` in EBX and result in EDI instead of original `this` in EDI and result in EBX.
// 3. Tried direct member access vs tactical local, raw pointer offsets, self/out locals, register locals, early declarations, single final store, explicit half formula, and flags /Oa /Og /Ot /Ob0 /G5 /Gs /GX /O1 /Od. No exact; best remains ordered expression with this/result register swap.
// BLOCKER: remaining mismatch is a register-allocation basin from byte 0 (EBX/EDI swapped), not localized drift.
// Top-20 scratch retry notes:
// try 1: baseline validation still exact size 117B, 41 positional diff bytes / 35.04%; first mismatch at prologue due EBX/EDI swap.
// try 2: hoisted result local declaration before tactical local; no codegen change.
// try 3: spelled `r = r - ...; r = r + ...` instead of compound assignments; no codegen change and still emits neg/add instead of original sub in the late arithmetic hunk.
// try 4: `register int r`; no codegen change.
// tries 5-7: re-reviewed prior scratch evidence for direct member/raw pointer/self/out locals and register locals; all previously landed in same EBX=this, EDI=result basin or worse.
// try 8: re-reviewed flag probes already recorded (/Oa /Og /Ot /Ob0 /G5 /Gs /GX /O1 /Od); no retained flag because default remains best exact-size/equal-byte result.
// try 9: accepted_drift review rejected: diff is mostly register allocation but spans prologue, branch-local EBX/EDI save timing, arithmetic hunk, final stores, and epilogues; not localized.
// try 10: final validation remains exact size 117B but broad 35.04% positional mismatch. GIVEUP.
// retry 11: Boss denied accepted_drift for prior broad mismatch; continued only as scratch matching work.
// retry 12: moved result declaration inside success branch and used compound assignments; no codegen change (same EBX=this/EDI=result, 35.04% pos / 24.79% edit).
// retry 13: removed tactical local and used direct `this->tacticalAI` member calls; no codegen change.
// retry 14: seeded `int r = 0` before tactical local and used `> r` guard to try occupying EBX before preserving this; no codegen change.
// retry 15: explicit `self = this` and `register self`; no codegen change.
// retry 16: modeled real nearby taimdmd class/inheritance/subobject layout from matching constructor and tested /GX donor flag; offset remains right but allocation unchanged, /GX not retained.
// GIVEUP: kept best 117B source in scratch. Do not propose accepted_drift; mismatch remains broad EBX/EDI allocation/topology.

class TribeTacticalAIModule {
public:
    int strategicNumber(int id);
};

extern "C" int __cdecl debug_rand(char* file, int line);

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1146C];
    TribeTacticalAIModule tacticalAI;
    char gap_after[0x12588 - 0x1146C - 1];
    int tributeChatTimeout;

    void setTributeChat();
};

void TribeMainDecisionAIModule::setTributeChat() {
    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (tactical->strategicNumber(0x7E) > 0) {
        int r;
        r = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x41D) % tactical->strategicNumber(0x7E);
        r -= tactical->strategicNumber(0x7E) / 2;
        r += tactical->strategicNumber(0x7D);
        this->tributeChatTimeout = r;
    } else {
        this->tributeChatTimeout = tactical->strategicNumber(0x7D);
    }
}
