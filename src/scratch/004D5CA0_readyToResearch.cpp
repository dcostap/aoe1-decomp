// TribeBuildAIModule::readyToResearch
// VA: 004D5CA0
// PDB: taibldmd.cpp:1700-1716
// Attempt log:
// try 1: replaced bad __fastcall helper with natural member/local class surface; exact body size needed one-byte padding pseudo-function, but broad EBX/EDI register drift remains.
// try 2: register id local for param_1; no change.
// try 3: register unsigned char state; no change.
// try 4: explicit result local/if-return; worsened return block shape, rolled back.
// try 5: id assigned in separate statement; no change.
// try 6: register parameter spelling; no change.
// GIVEUP: current natural source is behaviorally close but not exact. Main unresolved issue is early register allocation: original saves ESI then EDI and keeps param_1 in EDI with `mov al,[esp+0Ch]` fallback; rebuilt saves EBX then ESI, keeps param_1 in EBX, uses ECX for boolean result, and shifts branch targets. One-byte trailing padding pseudo-function is present only because configured range includes the post-ret NOP. Not proposing accepted_drift because drift is broad register/topology/layout, not a small localized hunk.

class TRIBE_Player {
public:
    unsigned char researchState(int research_id);
};

class MasterAI {
public:
    char gap_00000[0x1256C];
    TRIBE_Player* aiPlayer;
};

class TribeBuildAIModule {
public:
    char gap_000[0x5BC];
    MasterAI* md;

    int readyToResearch(int param_1, int param_2);
};

int TribeBuildAIModule::readyToResearch(register int param_1, int param_2)
{
    unsigned char state;

    if (param_2 == 1) {
        if (param_1 == 2) {
            state = md->aiPlayer->researchState(0x65);
        }
        else {
            state = (unsigned char)param_1;
        }
        if (param_1 == 3) {
            state = md->aiPlayer->researchState(0x66);
        }
        if (param_1 == 4) {
            state = md->aiPlayer->researchState(0x67);
            return state == 1;
        }
    }
    else {
        state = md->aiPlayer->researchState(param_1);
    }

    return state == 1;
}

// PSEUDO-FUNCTION: one-byte padding included in configured range.
__declspec(naked) void padding_pseudo_function(void) {
    __asm _emit 0x90
}
