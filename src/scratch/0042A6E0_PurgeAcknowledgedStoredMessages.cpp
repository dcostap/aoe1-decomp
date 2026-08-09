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

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void operator_delete(void* ptr);

struct RESENDER {
    unsigned int state;
    unsigned int serial;
    void* data;
    unsigned int reserved;
    unsigned int acknowledgements[10];
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

        if (resend->serial != 0) {
            unsigned int player;

            for (player = 1; player <= (unsigned int)this->MaxGamePlayers; player++) {
                if (this->IsPlayerHuman(player)) {
                    if (resend->acknowledgements[player] > 0) {
                        nonAckCount++;
                    }
                }
            }

            if (nonAckCount == 0) {
                L->Log("GTD: Ser #%d Slot=%d  Ackd by all. (Released)",
                    resend->serial, slot);

                void* data = resend->data;
                resend->state = 0;
                if (data != 0) {
                    operator_delete(data);
                }
                resend->data = 0;
                resend->serial = 0;
                resend->reserved = 0;

                for (int i = 0; i < 10; i++) {
                    resend->acknowledgements[i] = 0;
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
            if (resend->serial != 0) {
                this->WaitingForAck++;
            }
            resend++;
            i--;
        } while (i != 0);
    }

    return 1;
}
