// 0042A6E0 PurgeAcknowledgedStoredMessages (283 bytes)
// PDB: Com_hand.cpp (TCommunications_Handler::PurgeAcknowledgedStoredMessages)
//
// Attempt log:
//   attempt 1: struct-based ResendSlot — 72.79% mismatch, VC5 pointerized inner loop
//   attempt 2: unsigned int* flat Resend — 67.84%, pointerized
//   attempt 3: void* Resend with explicit byte casts — 59.01%, still pointerized + dword counter folded
//   attempt 4: explicit *(uint*)((char*)Resend + (serial+p)*4) — same 59.01%
//   attempt 5: do/while inner loop with int player — 59.36%, jle instead of jbe
//   attempt 6: idx temp variable — same as 4
//   attempt 7: unsigned cast for comparison — 59.01%, jbe fixed but pointerization remains
//   attempt 8: /O1 flag — produced 262B (21 bytes short), wrong size
//
// Root cause: VC5 strength-reduces Resend[dword_serial + player] where player increments
// by 1 into a byte pointer (edi starts at (dword_serial+1)*4, increments by 4). The original
// VC5 keeps the LEA+scaled-index pattern (lea ecx,[esi+edi]; cmp [edx+ecx*4],0).
// Also folds the dword_serial loop counter into a byte-offset counter.
//
// The outer loop, purge block, and second counting loop are structurally correct.
// Left in scratch: remaining drift is inner-loop strength reduction (VC5 codegen artifact)
// and loop-counter conversion (dword → byte offset). Behavior is fully equivalent.

// Current worker probes:
//   baseline: retained the prior flat-pointer reconstruction; it emits the right size/frame
//             and calls but folds the dword-index cursor into a byte-offset cursor.
//   RESENDER member/anchored access variants and signed cursor: no improvement; reverted.
//   unsigned acknowledgement `> 0`: restores the original jbe, improving shape only.
//   named post-call index, flat clear cursor, counted-for spelling: emitted-code duplicate.
//   243-variant source lab (member/flat access and update-order axes): no exact result.
//   five index-scope variants: one emitted-code group, no change.
//   /Og- context: broad EBP frame (437-448 bytes), rejected.
//   left in scratch: size/frame/call set match; remaining 182 positional bytes are the
//   independent dword cursor collapsed into a byte-offset induction by VC5.
// Main-agent normalization removed the compiler-steering flat byte/dword cursors
// from living source and restored ordinary RESENDER indexing. The cleaner source
// validates at 255 bytes / 266 differing bytes; behavior and ordered calls remain.
//
// Worker pass sa-49ac68ff-r1 found a 14-byte diagnostic using independent flat
// dword and byte cursors. Main-agent audit restored the owning RESENDER record
// array: the flatter form was compiler-steering plumbing, not plausible living
// source. Its codegen result remains useful evidence for the address-family gap.
//
// Attempt log (orch-comhand-02, 2026-08-10):
// baseline: confirmed the restored natural RESENDER reconstruction at 255B/266B;
// frame, CFG, and ordered calls are present but the compiler strength-reduces the
// inner DestMap walk and loses 28 bytes against the 283B oracle.
// behavior: temporarily reinstated the same-TU CountWaitingMessages-style flat
// cursor with independent byte and dword indices. This is binary-close (283B,
// 14B diff, 93.26% shape, 3/3 calls) and confirms the address-family blocker, but
// it was restored out of living source because it is compiler-steering rather than
// the canonical RESENDER ownership model.
// layout: direct flat subscripting, typed RESENDER/DestMap views, and moving the
// acknowledgment base before the IsPlayerHuman call all worsened the close basin
// (182-216B diffs). Three focused labs (16 flat forms, 10 typed index orders, and
// 8 offset-origin forms) found no exact output; the best offset-origin group was
// 13B only with an incorrect acknowledgment index and still had the wrong inner
// address shape. A constant-base-plus-index spelling likewise remained 182B.
// bounded-pass conclusion: the remaining gap is VC5's inner-loop induction/address
// family (oracle keeps `lea ecx,[esi+edi]; [base+ecx*4]` while natural forms fold
// one cursor). Restored the normalized RESENDER source; no shared files changed.
//
// Attempt log (sa5d6afc9d_r1, 2026-08-11):
// baseline: confirmed canonical RESENDER ownership at 255B/266B diff; checker
// remains structural because VC5 folds the current-record and DestMap inductions.
// layout: a typed RESENDER with a separate proven byte offset, dword DestMap index,
// and raw outer record accesses reached 283B/182B diff, preserving frame and calls;
// the compiler still emitted a byte-offset DestMap induction (EDI=14h, add 4).
// liveness/control-flow: anchored pointers, named per-player indices, pointer aliases,
// inline record-base dword casts, and reversed sum terms were duplicate or regressed;
// no variant recovered the oracle's `lea [player+dest_index]; [base+index*4]` family.
// bounded-pass conclusion: restored the pinned clean normalized RESENDER source;
// diagnostic 182B typed-flat basin remains history evidence, not living source.

// Attempt log (sat-42A6E0-normalize, 2026-08-12):
// normalized RESENDER to the proven 0x38-byte donor layout and field names
// TimeSent, Serial, ResendMsg, Length, and DestMap. Canonical offsets are +0,
// +4, +8, +0C, and +10. Validation is 255B/266B, 80.90% shape, 0xC frame,
// and 3/3 ordered calls. No codegen hypothesis was run.

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void operator_delete(void* ptr);

struct RESENDER {
    unsigned int TimeSent;
    unsigned int Serial;
    char* ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];
};

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;   // +0x12D8
    char gap_12DA[0x242];
    int WaitingForAck;               // +0x151C
    RESENDER* Resend;

    int IsPlayerHuman(unsigned int player);
    int PurgeAcknowledgedStoredMessages();
};

int TCommunications_Handler::PurgeAcknowledgedStoredMessages()
{
    int slot = 0;
    do {
        int nonAckCount = 0;
        RESENDER* resend = &this->Resend[slot];

        if (resend->Serial != 0) {
            unsigned int player;

            for (player = 1; player <= (unsigned int)this->MaxGamePlayers; player++) {
                if (this->IsPlayerHuman(player)) {
                    if (resend->DestMap[player] > 0) {
                        nonAckCount++;
                    }
                }
            }

            if (nonAckCount == 0) {
                L->Log("GTD: Ser #%d Slot=%d  Ackd by all. (Released)",
                    resend->Serial, slot);

                char* data = resend->ResendMsg;
                resend->TimeSent = 0;
                if (data != 0) {
                    operator_delete(data);
                }
                resend->ResendMsg = 0;
                resend->Serial = 0;
                resend->Length = 0;

                for (int i = 0; i < 10; i++) {
                    resend->DestMap[i] = 0;
                }
            }
        }

        slot++;
    } while (slot < 502);

    // Count remaining non-zero serials into WaitingForAck
    {
        RESENDER* resend = this->Resend;
        int i = 502;

        do {
            if (resend->Serial != 0) {
                this->WaitingForAck++;
            }
            resend++;
            i--;
        } while (i != 0);
    }

    return 1;
}
