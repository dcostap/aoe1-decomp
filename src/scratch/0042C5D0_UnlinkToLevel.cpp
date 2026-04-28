// TCommunications_Handler::UnlinkToLevel
// VA: 0042C5D0, Com_hand.cpp:4664-4692
// Status: PARKED in scratch - VC5 loop peeling (do-while first-iteration unrolling)
//
// Attempt log:
// v0: if (cond) { do { } while (cond2); } → VC5 unrolls first iteration, 2 calls
// v1: Using local vars in success path scope → same unrolling
// v2: while (!cond) { } else { do {} while (cond2); } → same unrolling  
// v3: while (cond) { } with original_status = new_status → adds mov edi,eax
// v4: for(;;) with breaks and continue → jmp unrolling
// v5: if (cond) goto success; do { } while (cond2); → same unrolling
// v6: goto-based explicit loop label → same unrolling
// v7: if (cond) {} else { do {} while (cond2); } → same unrolling
//
// All 7 probes produce EXACTLY the same loop structure:
//   - First call at 0x0D, exit check at 0x1E, loop-back to second call at 0x24
//   - Original has ONE call at 0x0D, loop-back jg to 0x0D
// The peeled iteration changes the block structure: success/failure paths shift,
// register allocation changes (edx vs edi in success path), branch offsets change.
//
// The 12 remaining diff bytes (after masking 12 relocations) are ALL from
// this peel + consequent register/offset changes.
//
// Struct layout: gap_00[0xFC5], TBuff[257], gap_10C6[0x20E], CommunicationsStatus at +0x12D4
// Globals: *(void**)0x62C4FC for debugging log L
// Functions: Log(void*, const char*, ...), sprintf

void __cdecl Log(void* log, const char* format, ...);
int __cdecl sprintf(char* buffer, const char* format, ...);

struct TCommunications_Handler {
    char gap_00[0xFC5];         // +0x00 to +0xFC4
    char TBuff[257];            // +0xFC5, size 0x101
    char gap_10C6[0x20E];       // +0x10C6 to +0x12D3
    int CommunicationsStatus;   // +0x12D4

    int AnalyzeCommunicationsStatus();
    int UnlinkCurrentLevel();
    int GetCommunicationsStatus(int status);
    int UnlinkToLevel(int param_1);
};

int TCommunications_Handler::UnlinkToLevel(int param_1) {
    int original_status;
    int new_status;

    // line 4666
    original_status = AnalyzeCommunicationsStatus();

    // line 4669
    CommunicationsStatus = original_status;
    Log(*(void**)0x62C4FC, "Unlink to level %d desired, currently at level %d",
        param_1, original_status);

    // lines 4671-4672: clamp param_1 to minimum 1
    if (param_1 < 1) {
        param_1 = 1;
    }

    // line 4674: read original status from memory (edi)
    original_status = CommunicationsStatus;

    // lines 4675-4678: unlink loop with entry check
    if (original_status <= param_1) {
        // skip loop, fall through to success
    } else {
        do {
            new_status = UnlinkCurrentLevel();
            CommunicationsStatus = new_status;
            if (new_status == original_status) {
                sprintf(TBuff, "Unlink from level [ %d ] Failed.\n Stopping connections",
                        original_status);
                Log(*(void**)0x62C4FC, TBuff);
                return AnalyzeCommunicationsStatus();
            }
        } while (new_status > param_1);
    }

    // line 4690: log success status
    {
        int reported = CommunicationsStatus;
        int current = GetCommunicationsStatus(reported);
        Log(*(void**)0x62C4FC, "AFTER UNLINKING...Status=%d   Reported=%d",
            current, reported);
    }

    // line 4691: final analysis
    return AnalyzeCommunicationsStatus();
}
