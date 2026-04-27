// 004F1090 TribeTacticalAIModule::removeObject(int objId) — first pass
#include "../../include/game_globals.h"
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void  __cdecl operator_delete(void*);
// Attempt log:
// Probe 1: managed array removal — scan for object, compact array
// Left in scratch — array management paired with extern helper call

class TribeTacticalAIModule {
public:
    char _gap_00[0xF0];
    void* md; int* val; int num; char _g1[4]; int max;
    char _gap_2[0x0D48 - 0x120];
    int* wa_val; int wa_num; char _g2[4]; int wa_max;
    
    void removeObject(int objId);
};

void __fastcall someHelper(int objId); // 004FBB30

void TribeTacticalAIModule::removeObject(int objId)
{
    someHelper(objId);
    
    // Scan array for matching element
    for (int i = 0; i < this->num; i++) {
        if (this->val[i] == objId) {
            // Compact: shift remaining elements
            for (int j = i; j < this->num - 1; j++) {
                this->val[j] = this->val[j + 1];
            }
            this->num--;
            break;
        }
    }
}
