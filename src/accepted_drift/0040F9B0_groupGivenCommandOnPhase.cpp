// VA: 0040F9B0 AIPlay::groupGivenCommandOnPhase
// PDB: aipbook.cpp lines 645-658 (132 bytes, 58 asm lines)
// Default flags. No inline asm/hacks.
// Attempt log:
// 1: Revalidated existing scratch: default optimized build was size-short 128 vs configured 132.
// 2: Assigned `groupValue = (unsigned char)cmd2->data[1]` to force original-like parameter stack-slot spill; still size-short.
// 3: Tried volatile unsigned char temp; exact size but worse register allocation/layout (64.39% positional), rolled back.
// 4: Tried assigning raw signed byte to groupValue; still size-short.
// 5: Probed /O2 /Oy /Og-: exact size but EBP-frame wrong basin from offset 0; removed flag.
// 6: Probed /Ob0, /G5, /G6, /Gr: still size-short 128; removed flags.
// 7: Probed /O1 /Oy: size-short 101; removed flag.
// 8: Used `*(unsigned char*)&groupValue = cmd2->data[1]` and `(groupValue & 0xff)` compare; exact size and best diff, but command group byte still sign-extended because entry data was signed char.
// 9: Changed command data to unsigned char; now first command-byte load matches original zero-extend, exact size, best current metrics.
// 10: Tried adding a local `type = typeValue`; no codegen change, kept harmlessly.
// ACCEPTED_DRIFT_APPROVED by Boss in top-20 retry mode: exact-size behavior-equivalent.
// Remaining drift is an EBX/EBP allocation swap for group/type values plus one local
// `mov eax,ebx` after reloading the intentionally spilled stack byte. Calls, stack
// cleanup, loop bounds, predicates, unsigned byte handling, memory effects, and
// returns match.

// AIPlayPhase::command() defined elsewhere (0040F110 already matching).
// The local declarations are standalone-only. The canonical wrapper uses the
// reviewed aipbook_context.h declarations without changing accepted behavior.

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhase_Entry_0040F110 {
public:
    unsigned char data[16];
};

class AIPlayPhase {
public:
    AIPlayPhase_Entry_0040F110 entries_[5];
    char triggers_area_[0x8C - 0x50];

    AIPlayPhase_Entry_0040F110* command(int index);
};

class AIPlay {
public:
    char pad_00[0x90];
    AIPlayPhase phases[10];

    int groupGivenCommandOnPhase(int groupValue, int typeValue, int phaseIndex);
};
#endif

int AIPlay::groupGivenCommandOnPhase(int groupValue, int typeValue, int phaseIndex)
{
    int type = typeValue;
    if (groupValue < 0 || groupValue >= 5)
        return -1;
    if (phaseIndex < 0 || phaseIndex >= 10)
        return -1;

    AIPlayPhase* phase = &this->phases[phaseIndex];
    for (int i = 0; i < 5; i++) {
        AIPlayPhaseCommand* cmd = phase->command(i);
        if ((unsigned int)cmd->groupValue == (unsigned int)groupValue) {
            AIPlayPhaseCommand* cmd2 = phase->command(i);
            *(unsigned char*)&groupValue = cmd2->typeValue;
            if ((groupValue & 0xff) == type) {
                return i;
            }
        }
    }
    return -1;
}
