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
// Struct layout: gap_00[0xFC5], TBuff[257], gap_10C6[0x20E], CommunicationsStatus at +0x12D4
// Globals: *(void**)0x62C4FC for debugging log L
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
    ((TDebuggingLog*)*(void**)0x62C4FC)->Log("Unlink to level %d desired, currently at level %d",
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
            ((TDebuggingLog*)*(void**)0x62C4FC)->Log("AFTER UNLINKING...Status=%d   Reported=%d",
                this->GetCommunicationsStatus(), this->CommunicationsStatus);
            return AnalyzeCommunicationsStatus();
        }

        new_status = UnlinkCurrentLevel();
        CommunicationsStatus = new_status;
    } while (new_status != original_status);

    sprintf(TBuff, "Unlink from level [ %d ] Failed.\n Stopping connections",
            original_status);
    ((TDebuggingLog*)*(void**)0x62C4FC)->Log(TBuff);
    return AnalyzeCommunicationsStatus();
}
