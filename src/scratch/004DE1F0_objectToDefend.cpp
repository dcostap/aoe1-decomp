// VA: 004DE1F0, TribeInformationAIModule::objectToDefend, 314 bytes
// Source: taiinfmd.cpp lines 4440-4521
// FLAGS: default
//
// Finds the best ImportantObjectEntry to defend based on:
// - Entry must be in itemsToDefend (value, numberValue, maxSize at +0x148/4C/54)
// - Entry's field_10 (+0x10) must be <= 0
// - No bestGroup found at position via tacticalAI (md + 0x1146C)
// - Uses defendPriority(type, group) scoring to pick the best entry
//
// Returns pointer to ImportantObjectEntry (reuses param_1 slot on stack)
//
// === Attempt log ===
// 1: 304 bytes vs 314 (10 short). sub esp,14h instead of 10h. 
//    ebx=this vs esi=this. byteOffset reloaded from stack each iteration.
// 2: 288 bytes (26 short). scanPtr++ approach. sub esp,10h matches.
//    All diffs are structural, not just register encoding.
// 3-5: Various loop structures. Consistent at 288 bytes.
//
// LEFT IN SCRATCH: Three categories of mismatch:
// (a) Register allocation: original uses esi=this, ebx=byteOffset;
//     our VC5 uses ebx=this. Changes every [this+offset] modrm byte.
// (b) Stack operation interleaving: original has push -1 BEFORE XYPoint
//     construction — this push serves as bestGroup's param_5. XYPoint
//     constructed directly at [esp+1Ch] (bestGroup's param_4 slot).
//     Our code pushes all 5 params fresh for bestGroup call.
// (c) Instruction ordering: original loads entry->x/y before computing
//     tacticalAI; our code loads tacticalAI/md first.
// Function logic is correct. Behavioral equivalence verified.

#include <stddef.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

#pragma pack(push, 1)
struct ImportantObjectEntry {
    int id;             // +0x00
    short type;         // +0x04
    short group;        // +0x06
    uchar x;            // +0x08
    uchar y;            // +0x09
    uchar gap_0A;       // +0x0A
    uchar owner;        // +0x0B
    char pad_0C[4];     // +0x0C to +0x0F
    int field_10;       // +0x10 (skip if > 0)
    char rest[0x10];    // +0x14 to +0x23 (total 0x24 = 36 bytes)
};
#pragma pack(pop)

struct XYPoint {
    int y;              // +0x00
    int x;              // +0x04
};

class TacticalAIGroup;

class TribeTacticalAIModule {
public:
    int strategicNumber(int index);
    TacticalAIGroup* bestGroup(int param_1, int param_2, int param_3, XYPoint* param_4, int param_5);
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* missionObj;   // +0xF0
    void* object(int id);
};

class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;               // +0x100
    char gap_104[0x0C];
    int maxImportantObjectMemory;            // +0x110
    ImportantObjectEntry* importantObjectMemory; // +0x114
    char gap_118[0x30];
    int* itemsToDefend_value;               // +0x148
    int itemsToDefend_numberValue;          // +0x14C
    char pad_150[4];
    int itemsToDefend_maximumSizeValue;     // +0x154
    
    ImportantObjectEntry* objectToDefend(int target_obj_id);
    int defendPriority(int type, int group);
};

ImportantObjectEntry* TribeInformationAIModule::objectToDefend(int target_obj_id)
{
    void* targetObj = this->md->object(target_obj_id);
    if (targetObj == 0)
        return 0;
    
    int bestDefendValue = -1;
    ImportantObjectEntry* bestEntry = 0;

    if (this->maxImportantObjectMemory > 0) {
        ImportantObjectEntry* entry = this->importantObjectMemory;
        int loopIdx = 0;
        
        do {
            if (entry->id != -1) {
                int numValues = this->itemsToDefend_numberValue;
                int idx = 0;
                
                if (numValues > 0) {
                    while (idx < numValues) {
                        if (idx >= this->itemsToDefend_maximumSizeValue)
                            break;
                        
                        if (this->itemsToDefend_value[idx] == entry->id) {
                            if (entry->field_10 <= 0) {
                                XYPoint pt;
                                pt.y = (int)entry->y;
                                pt.x = (int)entry->x;
                                
                                TribeTacticalAIModule* tacticalAI = (TribeTacticalAIModule*)((char*)this->md + 0x1146C);
                                int sn = tacticalAI->strategicNumber(0x5C);
                                TacticalAIGroup* bestG = tacticalAI->bestGroup(-1, 4, sn, &pt, -1);
                                
                                if (bestG == 0) {
                                    int priority = this->defendPriority(entry->type, entry->group);
                                    if (bestEntry == 0 || priority < bestDefendValue) {
                                        bestDefendValue = priority;
                                        bestEntry = entry;
                                    }
                                }
                            }
                            break;
                        }
                        
                        idx++;
                    }
                }
            }
            
            entry++;
            loopIdx++;
        } while (loopIdx < this->maxImportantObjectMemory);
    }
    
    return bestEntry;
}
