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

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* L;

void operator_delete(void* ptr);

class TCommunications_Handler {
public:
    char gap_00[0x12D8];
    unsigned short MaxGamePlayers;   // +0x12D8
    char gap_12DA[0x242];
    int WaitingForAck;               // +0x151C
    unsigned int* Resend;            // +0x1520 — flat dword array, each slot = 14 dwords (0x38 bytes)

    // Slot layout (dword offsets from slot base):
    //   [0] = field_0
    //   [1] = serial number
    //   [2] = data pointer (void*)
    //   [3] = field_C
    //   [4..13] = player ack flags (10 dwords for players 1-9, [4] unused)

    int IsPlayerHuman(unsigned int player);
    int PurgeAcknowledgedStoredMessages();
};

int TCommunications_Handler::PurgeAcknowledgedStoredMessages()
{
    int slot = 0;
    int byte_offset = 0;
    unsigned int dword_serial = 4;   // flat dword index of current slot's player ack[0]

    // Iterate over 502 stored-message slots (serial range 4..0x1B6A, step 14)
    do {
        int nonAckCount = 0;

        // Check if slot has a pending message (serial != 0)
        if (*(unsigned int*)((char*)this->Resend + byte_offset + 4) != 0) {
            unsigned int player;

            // For each human player, check if they've acknowledged
            for (player = 1; player <= (unsigned int)this->MaxGamePlayers; player++) {
                if (this->IsPlayerHuman(player)) {
                    if (this->Resend[dword_serial + player] != 0) {
                        nonAckCount++;
                    }
                }
            }

            // If all human players have acknowledged, purge the slot
            if (nonAckCount == 0) {
                L->Log("GTD: Ser #%d Slot=%d  Ackd by all. (Released)",
                    *(unsigned int*)((char*)this->Resend + byte_offset + 4), slot);

                unsigned int* elem = (unsigned int*)((char*)this->Resend + byte_offset);
                void* data = *(void**)(elem + 2);
                elem[0] = 0;
                if (data != 0) {
                    operator_delete(data);
                }
                elem[2] = 0;
                elem[1] = 0;
                elem[3] = 0;

                // Zero the 10-dword player ack area
                for (int i = 0; i < 10; i++) {
                    elem[4 + i] = 0;
                }
            }
        }

        dword_serial += 14;
        slot++;
        byte_offset += 0x38;
    } while (dword_serial <= 0x1B6A);

    // Count remaining non-zero serials into WaitingForAck
    {
        unsigned int* p = this->Resend + 1;  // start at first slot's serial field
        int i = 0x1F6;                       // 502 slots

        do {
            if (*p != 0) {
                this->WaitingForAck++;
            }
            p += 14;  // next slot's serial field
            i--;
        } while (i != 0);
    }

    return 1;
}
