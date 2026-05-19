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
// 2026-05-19 Boss pass: volatile dword reload for param_1 produced near-match: first 96 bytes exact, total 10 byte diffs (ECX vs EDX for boolean materialization and EAX/EDX vs ECX/EAX in non-param2==1 md load/push sequence), 6.8966% positional/edit.
// Additional 20 return/else variants (result local, ternary, if-return, md/player locals, volatile param in else) did not improve; most stayed the same 10-byte drift, some regressed to 30%+.
// ACCEPTED_DRIFT_CANDIDATE: remaining diff is register allocation only. Calls, constants, branch targets, stack cleanup, return values, memory effects, and control flow match; ECX vs EDX boolean zero/sete/mov is equivalent, and non-mode-1 path loads the same md/param and calls the same researchState with same argument/this.

class TRIBE_Player { public: unsigned char researchState(int); };
class MasterAI { public: char gap[0x1256C]; TRIBE_Player* aiPlayer; };
class TribeBuildAIModule { public: char gap[0x5BC]; MasterAI* md; int readyToResearch(int,int); };

int TribeBuildAIModule::readyToResearch(int param_1,int param_2){
    unsigned char state;
    if(param_2==1){
        int id=*(int volatile*)&param_1;
        if(id==2)
            state=md->aiPlayer->researchState(0x65);
        else
            state=(unsigned char)*(unsigned char*)&param_1;
        if(id==3)
            state=md->aiPlayer->researchState(0x66);
        if(id==4){
            state=md->aiPlayer->researchState(0x67);
            return state == 1;
        }
    } else {
        state=md->aiPlayer->researchState(param_1);
    }
    return state == 1;
}

// PSEUDO-FUNCTION: one-byte padding included in configured range.
__declspec(naked) void padding_pseudo_function(void){ __asm _emit 0x90 }
