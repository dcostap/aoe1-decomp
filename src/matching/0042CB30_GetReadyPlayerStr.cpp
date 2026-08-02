// 0042CB30 GetReadyPlayerStr (TCommunications_Handler::GetReadyPlayerStr)
// Attempt log:
// inherited scratch variants: do/for/goto, p computed inside, literal/default local, unsigned casts all converged to compact edx=this/running-buffer-pointer family.
// tried direct one-based index expressions: 176B (too short), still running-buffer pointer.
// tried local this alias and register i: no change.
// tried volatile MaxGamePlayers: 179B but wrong ebx=this family, still running buffer pointer and hoisted current_turn.
// tried volatile current_turn only (current source): 179B and reloads current_turn each iteration, but still wrong ebx=this, esi=max_count, eax=buffer pointer family.
// tried register/split default char; VC5 still immediate '?' rather than original bl=3Fh.
// left in scratch: behavior is understood; remaining gap is broad VC5 register-allocation/induction-variable basin (original ebp=this, eax=i, edx=record pointer, bl='?', reload max into cx at bottom).
// Retry 2026-05-26 Boss pass: 17 probes on VA 0042CB30 only. Revalidated current source: 179B, 58.6592% positional / 70.3911% edit, first mismatch byte 0. Tried nonvolatile current_turn, this/self alias to encourage EBP, direct indexed volatile stores, reloading MaxGamePlayers each loop, `MaxGamePlayers != 0` guard, default immediate '?' instead of defc, if/else chain instead of switch, buffer-base expression, and flags /G5 /Oa /Og /Ob0 /Oy- /O1 /Od. Competitive variants all kept the wrong EBX=this / ESI=count or running-buffer-pointer basin; /O1 shrank and /Od was broad wrong. GIVEUP: not accepted_drift quality; mismatch is broad prologue/register allocation plus induction-variable/switch layout, not a localized equivalent hunk.
// probe 5: use external data symbols for the known string and output buffer so VC5 sees
// named global arrays instead of folding an absolute pointer into a running output cursor.
// probe 6: reversed the inclusive predicate; codegen stayed at 14B, so restored the original arm spelling.
// probe 7: put the switch under the observed less-than arm; codegen widened to 37B, so restored probe 5.
// probe 8: named the LastTurnAck cursor value before the comparison; no emitted-code change.
// probe 9: narrow volatile LastTurnAck read recovered load order and reduced drift to 5B; later audit removed it without codegen change.
// probe 10: reordered cases to the binary/PDB line order (2,4,0,6,5,default); exact match.
// source audit: removed volatile current_turn, volatile LastTurnAck, and register qualifier independently;
// all no-history checks remained exact, so the retained source is the natural nonvolatile form.

#include <string.h>
#pragma intrinsic(strcpy)

extern char ReadyPlayerBuffer[];
extern const char ReadyPlayerTemplate[];

class TCommunications_Handler {
public:
    char gap_10C8[0x10C8];
    unsigned long current_turn;
    char gap_10CC[0x20C];
    unsigned short MaxGamePlayers;

    char* GetReadyPlayerStr();
};

char* TCommunications_Handler::GetReadyPlayerStr() {
    strcpy(ReadyPlayerBuffer, ReadyPlayerTemplate);

    unsigned int i = 1;
    if (i <= this->MaxGamePlayers) {
        int* p = (int*)((char*)this + 0x16D8);
        char defc;
        defc = '?';
        do {
            unsigned long last_turn_ack = p[0x13];
            if (last_turn_ack >= this->current_turn) {
                ReadyPlayerBuffer[i + 6] = 'A';
            } else {
                switch (p[0]) {
                case 2: ReadyPlayerBuffer[i + 6] = 'W'; break;
                case 4: ReadyPlayerBuffer[i + 6] = 'C'; break;
                case 0: ReadyPlayerBuffer[i + 6] = '-'; break;
                case 6: ReadyPlayerBuffer[i + 6] = 'V'; break;
                case 5: ReadyPlayerBuffer[i + 6] = 'X'; break;
                default: ReadyPlayerBuffer[i + 6] = defc; break;
                }
            }
            ++i;
            ++p;
        } while (i <= this->MaxGamePlayers);
    }
    return ReadyPlayerBuffer;
}
