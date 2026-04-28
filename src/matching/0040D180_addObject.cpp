// 0040D180 MainDecisionAIModule::addObject
// PDB: aimdmod.cpp:82-87, 207 bytes
// __thiscall, returns int, ret 4
// FLAGS: default
//
// Attempt log:
// probe 1-2: 89.9% - all regs saved at entry, no deferral past early return
// probe 3: if(obj){body}return0 -> 16.4%, body 166 bytes MATCH!
//   Only diff is register save placement (entry vs body)
// probe 4: return (int)obj -> back to 89.9%
// probe 5: goto done for found-match case -> MATCH (0.0000%!)
//   Key: `goto done` forces VC5 to use a single shared epilogue for BOTH
//   the found-match case and the normal function end. Without `goto`,
//   VC5 uses `return 1;` inline which changes epilogue structure and
//   register save deferral decisions.

#include <stdlib.h>

class RGE_Static_Object {
public:
    char gap_00[4];
    int id;                        // +0x4
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

class MainDecisionAIModule {
public:
    char gap_00[0xF0];          // AIModule base class
    void* player;                // +0xF0: RGE_Player*
    int* objects_value;          // +0xF4
    int objects_numberValue;     // +0xF8
    int objects_pad_FC;          // +0xFC
    int objects_maximumSizeValue; // +0x100

    int addObject(RGE_Static_Object* obj);
};

int MainDecisionAIModule::addObject(RGE_Static_Object* obj) {
    if (obj == NULL) return 0;

    int count = this->objects_numberValue;
    int id = obj->id;

    for (int i = 0; i < count; i++) {
        if (i >= this->objects_maximumSizeValue) break;
        if (this->objects_value[i] == id) goto done;
    }

    if (count > this->objects_maximumSizeValue - 1) {
        int newSize = count + 1;
        int* new_arr = (int*)operator_new(newSize * 4);
        if (new_arr != NULL) {
            int j = 0;
            while (j < this->objects_maximumSizeValue && j < newSize) {
                new_arr[j] = this->objects_value[j];
                j++;
            }
            operator_delete(this->objects_value);
            this->objects_value = new_arr;
            this->objects_maximumSizeValue = newSize;
        }
    }

    this->objects_value[this->objects_numberValue] = id;
    this->objects_numberValue++;

done:
    return 1;
}
