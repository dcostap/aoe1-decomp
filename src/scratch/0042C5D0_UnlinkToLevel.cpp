// TCommunications_Handler::UnlinkToLevel
// VA: 0042C5D0, Com_hand.cpp:4664-4692
// Status: PAUSED in scratch - natural loop matches structure; log-call scheduling remains.
//
// Attempt log (Luna42C5D0, 2026-08-02):
// baseline: outer if/do form was 198B with an extra UnlinkCurrentLevel call from VC5's
// first-iteration peeling (110 strict diff bytes, 70% call alignment).
// control-flow: reconstructed the source-plausible do loop with its level test at the
// top, then UnlinkCurrentLevel, status store, and `while (new_status != original_status)`.
// This removed the extra call and reached 179B, 9/9 ordered calls, 95% shape, and 46
// strict diff bytes (first mismatch +0x4D / VA 0042C61D).
// abi: the success log must inline `GetCommunicationsStatus(), CommunicationsStatus`;
// this preserves the binary's pre-pushed status argument across the no-argument refresh.
// explicit this, register-qualified/local reported values, the donor extern-L surface,
// and a proven COMMSTATUS enum were tested; the enum and typed variadic Log surface are
// retained as canonical source but produce the same 179B codegen basin.
// variant: a 15-case success-argument/failure-log lab (size and call-set gated) collapsed
// to one emitted group; no exact variant. Final validated gap is localized to the success
// and failure Log setup: target uses EDX/status then ECX/this and pushes EAX before loading
// L, while the rebuild uses ECX/status then pushes before setting this and chooses a
// different L load register. Not accepted_drift: this is compiler scheduling drift.
//
// Attempt log (orch-w9, 2026-08-07):
// Re-examined the 46B gap with fresh labs (~50 variants) after the Luna pause.
// target success Log: mov edx,[esi+12D4h]; mov ecx,esi; push edx; call Get;
//   push eax; mov eax,[62C4FCh]; push fmt; push eax; call Log  (t1->edx, t2->eax,
//   t2 load AFTER arg2 push; A1 short form).
// rebuilt success Log: mov ecx,[esi+12D4h]; push ecx; mov ecx,esi; call Get;
//   mov edx,[62C4FCh]; push eax; push fmt; push edx; call Log  (t1->ecx, t2->edx,
//   t2 load BEFORE arg2 push; 8B15 long form -> success block +1 byte -> je disp 33/34).
// failure Log: target L->ecx (8B0D), rebuilt L->eax (A1) -- -1 byte offsets the success +1.
//
// Axes collapsed to the same 179B/46B basin (or worse):
//  - call-site spelling: member/static/free Log, inline/unqualified/raw/volatile/add_zero
//    success args, direct/local/cast failure Log (prior lab + lab2/lab4)
//  - reported arg: inline member, clean COMMSTATUS reported local, new_status local
//    (new_status -> 176B push-eax basin, proves the original read the MEMBER, not the local)
//  - class layout: truncated vs full real 0x1774 donor layout (from 0042BAE0) -- no change
//  - Log/L/sprintf declarations: extern TDebuggingLog* L, G_LOG_PTR int, member __cdecl,
//    static member, extern "C"/C++ sprintf, void/int sprintf return -- no change
//  - TU headers: stdio.h/string.h/stdlib.h -- no change
//  - flags: /O1 /Ox /Og- /Ot- /Oa /GX (vc5-risky preset), /G5 /G6 -- all worse
//    (prologue/first-Log order breaks; default /O2 /Oy is correct)
//  - two-local success form (reported + current at declaration) -- 78B, +1 size (worse)
//
// Conclusion: the two Log call setups land in a genuine VC5 register-allocator/scheduler
// basin (t1 in ecx + t2 in edx + failure-L in eax) that no clean period-plausible source
// spelling, declaration surface, layout, or flag steers to the target's (t1 in edx +
// t2 in eax + failure-L in ecx). Same instruction multiset, same pushes, same call set;
// only register choice and one push order differ. The target pattern matches exact donors
// (RequestResumeGame 0042C9E2 t1->edx; TXAcknowledgeMessage 0042A5FB L->eax-after-push;
// UnlinkCurrentLevel 0042BAFB 2-arg L->ecx), so it is the common VC5 idiom -- the rebuilt
// basin is the odd one. Left in scratch: compiler scheduling drift, not accepted_drift.
// Next lead: the only unexplored axis is reproducing the ORIGINAL Com_hand.cpp TU header
// pile (project headers beyond stdio/string/stdlib) or a full-TU compile; class surface
// and standard headers already tested negative.
//
// Attempt log (orch-luna-42c5d0-w1, 2026-08-09):
// context/layout: full generated TDebuggingLog (0x7B0) fields and the living
// Windows/game-global header did not change the 179B emission; the complete
// COMMSTATUS enumerator surface was also neutral.
// liveness: volatile logger-pointer access and a separate declaration/assignment
// for the reported status were neutral; eight register-qualified parameter/local
// variants collapsed to the same 179B group.
// context/flags: a typed external L pointer worsened relocation/codegen to 52B;
// /Zd, /Zi, and /Z7 debug-context variants were neutral. Restored the clean raw
// absolute-global/member-Log source after every diagnostic probe.
// fresh-pass conclusion: the only remaining drift is the same localized success
// and failure Log register/push scheduling (46 strict bytes, 95% shape, 9/9 calls);
// no new source/layout/header/flag lead was found.
//
// Struct layout: gap_00[0xFC5], TBuff[257], gap_10C6[0x20E], CommunicationsStatus at +0x12D4
// Globals: extern TDebuggingLog* L (original image address 0x62C4FC)
// Functions: TDebuggingLog::Log(char*, ...), sprintf

int __cdecl sprintf(char* buffer, const char* format, ...);

enum COMMSTATUS {
    COMMSTATUS_UNINITIALIZED = 0,
    INITIALIZED = 1
};

class TDebuggingLog {
public:
    void __cdecl Log(char* format, ...);
};

extern TDebuggingLog* L;

struct TCommunications_Handler {
    char gap_00[0xFC5];         // +0x00 to +0xFC4
    char TBuff[257];            // +0xFC5, size 0x101
    char gap_10C6[0x20E];       // +0x10C6 to +0x12D3
    COMMSTATUS CommunicationsStatus; // +0x12D4

    COMMSTATUS AnalyzeCommunicationsStatus();
    COMMSTATUS UnlinkCurrentLevel();
    COMMSTATUS GetCommunicationsStatus();
    COMMSTATUS UnlinkToLevel(COMMSTATUS param_1);
};

COMMSTATUS TCommunications_Handler::UnlinkToLevel(COMMSTATUS param_1) {
    COMMSTATUS original_status;
    COMMSTATUS new_status;

    // line 4666
    original_status = AnalyzeCommunicationsStatus();

    // line 4669
    CommunicationsStatus = original_status;
    L->Log("Unlink to level %d desired, currently at level %d",
        param_1, original_status);

    // lines 4671-4672: clamp param_1 to minimum 1
    if (param_1 < 1) {
        param_1 = INITIALIZED;
    }

    // line 4674: read original status from memory (edi)
    original_status = CommunicationsStatus;
    new_status = original_status;

    // lines 4675-4678: unlink loop with the level check at the top
    do {
        if (new_status <= param_1) {
            L->Log("AFTER UNLINKING...Status=%d   Reported=%d",
                this->GetCommunicationsStatus(), this->CommunicationsStatus);
            return AnalyzeCommunicationsStatus();
        }

        new_status = UnlinkCurrentLevel();
        CommunicationsStatus = new_status;
    } while (new_status != original_status);

    sprintf(TBuff, "Unlink from level [ %d ] Failed.\n Stopping connections",
            original_status);
    L->Log(TBuff);
    return AnalyzeCommunicationsStatus();
}
