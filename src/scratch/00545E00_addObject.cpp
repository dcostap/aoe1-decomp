// 00545E00 RGE_Game_World::addObject (World.cpp:3679-3760)
// Attempt log:
// 1: Natural implementation with virtual class but explicit offsets not vptr-adjusted: 61.27% diff; all fields +4.
// 2: Adjust class padding for implicit vptr: offsets fixed, diff 60.18%; compiler keeps newMax in EBX/newList in EDI, original EBP/EBX, zero loop manual not rep stosd.
// 3: Register newList got newList=EBX but newMax=EDI and indexed zero still manual; edit diff improved to 23.85%.
// 4: Pointer/count zeroing with register newList regressed edit diff to 27.79%; kept for now.
// 5: Explicit vptr/non-virtual method made no codegen difference.
// 6: memset tail zeroing slightly improved positional to 58.21 but still not original.
// 7: Removing register with memset recovers original EBX=newList/EBP=newMax and EDI slot in negative, but memset emits extra byte-tail rep; 58.21%.
// 8: No-register pointer/count zeroing regressed to newMax=EBX/newList=EDI and manual loop.
// 9: No-register indexed zeroing improved edit diff to 23.85%, but newMax remains EDI not original EBP.
// 10: Hoist newMax/newList/i declarations to function top: no codegen change.
// Left in scratch: behavior/calls/field offsets look correct, but remaining mismatch is VC5 register allocation and zero-tail basin in resize blocks. Best source gets EBX=newList and EDI=newMax (original EBP=newMax) and emits indexed zero loop instead of original `mov ecx,ebp; lea edi,[ebx+eax*4]; sub ecx,eax; xor eax,eax; rep stosd`; this shifts positive/negative branch targets from first mismatch offset 0x16.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern void* VIS_UNIT_objectsValue;
extern "C" void* __cdecl memset(void*, int, unsigned int);

class RGE_Static_Object {
public:
    void* vtbl;
    int id;
    void change_unique_id();
};

class RGE_Game_World {
public:
    void* vtbl;
    char pad_004[0x74 - 4];
    unsigned char scenario_object_flag; // +74
    char pad_075[0x88 - 0x75];
    RGE_Static_Object** objectsValue;   // +88
    int numberObjectsValue;             // +8c
    int maxNumberObjectsValue;          // +90
    RGE_Static_Object** negativeObjectsValue; // +94
    int numberNegativeObjectsValue;     // +98
    int maxNumberNegativeObjectsValue;  // +9c

    int addObject(RGE_Static_Object* obj);
};

int RGE_Game_World::addObject(RGE_Static_Object* obj)
{
    int newMax;
    RGE_Static_Object** newList;
    int i;
    int id = obj->id;
    if (id >= 0) {
        if (this->maxNumberObjectsValue - 1 < id) {
            newMax = this->maxNumberObjectsValue * 2;
            if (newMax < id) {
                newMax = (int)((float)id * 1.5f);
            }
            newList = (RGE_Static_Object**)operator_new(newMax * 4);
            if (newList == 0) return 0;
            i = 0;
            if (this->maxNumberObjectsValue > 0) {
                do {
                    newList[i] = this->objectsValue[i];
                    i++;
                } while (i < this->maxNumberObjectsValue);
            }
            if (i < newMax) {
                do {
                    newList[i] = 0;
                    i++;
                } while (i < newMax);
            }
            operator_delete(this->objectsValue);
            this->objectsValue = newList;
            VIS_UNIT_objectsValue = newList;
            this->maxNumberObjectsValue = newMax;
        }
        RGE_Static_Object* old = this->objectsValue[obj->id];
        this->objectsValue[obj->id] = obj;
        this->numberObjectsValue++;
        if (old != 0 && this->scenario_object_flag != 0) {
            this->scenario_object_flag = 0;
            old->change_unique_id();
            return 1;
        }
    } else {
        int slot = -id;
        if (this->maxNumberNegativeObjectsValue - 1 < slot) {
            newMax = this->maxNumberNegativeObjectsValue * 2;
            if (newMax < slot) {
                newMax = (int)((float)slot * 1.5f);
            }
            newList = (RGE_Static_Object**)operator_new(newMax * 4);
            if (newList == 0) return 0;
            i = 0;
            if (this->maxNumberNegativeObjectsValue > 0) {
                do {
                    newList[i] = this->negativeObjectsValue[i];
                    i++;
                } while (i < this->maxNumberNegativeObjectsValue);
            }
            if (i < newMax) {
                do {
                    newList[i] = 0;
                    i++;
                } while (i < newMax);
            }
            operator_delete(this->negativeObjectsValue);
            this->negativeObjectsValue = newList;
            this->maxNumberNegativeObjectsValue = newMax;
        }
        this->negativeObjectsValue[slot] = obj;
        this->numberNegativeObjectsValue++;
    }
    return 1;
}
