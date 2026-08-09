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

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void operator_delete(void* ptr);

struct RESENDER {
    unsigned long TimeSent;     // +0x00
    unsigned int Serial;         // +0x04
    char* ResendMsg;              // +0x08
    unsigned int Length;         // +0x0C
    unsigned int DestMap[10];    // +0x10
};

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;   // +0x12D8
    char gap_12DA[0x242];
    int WaitingForAck;               // +0x151C
    RESENDER* Resend;                // +0x1520 — 502 entries, each 14 dwords (0x38 bytes)

    // Slot layout (dword offsets from slot base):
    //   [0] = TimeSent
    //   [1] = serial number
    //   [2] = data pointer (void*)
    //   [3] = field_C
    //   [4..13] = player ack flags (10 dwords for players 1-9, [4] unused)

    int IsPlayerHuman(unsigned int player);
    int PurgeAcknowledgedStoredMessages();
};

int TCommunications_Handler::PurgeAcknowledgedStoredMessages()
{
    for (int slot = 0; slot < 502; ++slot) {
        RESENDER& resend = this->Resend[slot];
        int nonAckCount = 0;

        if (resend.Serial != 0) {
            unsigned int player;

            for (player = 1; player <= (unsigned int)this->MaxGamePlayers; player++) {
                if (this->IsPlayerHuman(player) && resend.DestMap[player] > 0) {
                    nonAckCount++;
                }
            }

            if (nonAckCount == 0) {
                L->Log("GTD: Ser #%d Slot=%d  Ackd by all. (Released)",
                       resend.Serial, slot);

                resend.TimeSent = 0;
                if (resend.ResendMsg != 0) {
                    operator_delete(resend.ResendMsg);
                }
                resend.ResendMsg = 0;
                resend.Serial = 0;
                resend.Length = 0;

                for (int i = 0; i < 10; i++) {
                    resend.DestMap[i] = 0;
                }
            }
        }
    }

    // Count remaining non-zero serials into WaitingForAck
    {
        RESENDER* p = this->Resend;
        int i = 0x1F6;                       // 502 slots

        do {
            if (p->Serial != 0) {
                this->WaitingForAck++;
            }
            p++;
            i--;
        } while (i != 0);
    }

    return 1;
}
