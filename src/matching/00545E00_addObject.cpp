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
// 11: A typed pointer/remaining clear and memset were diagnostic variants; the
// pointer loop stayed in a separate branch basin and memset used byte-count
// conversion.  Restored the natural indexed for-header clear.
// 12: `for (; i < newMax; i++) newList[i] = 0` in both resize arms restores
// the original rep stosd setup, saved-register coloring, and exact 457-byte
// output.  The named arrays and +0x88..+0x9C ownership remain canonical.

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern void* VIS_UNIT_objectsValue;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    void change_unique_id();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
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
                for (; i < newMax; i++) {
                    newList[i] = 0;
                }
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
                for (; i < newMax; i++) {
                    newList[i] = 0;
                }
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
