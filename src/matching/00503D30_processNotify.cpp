// 00503D30 TribeHuntedAnimalUnitAIModule::processNotify
// PDB: taiuaimd.cpp:99-136, 256 bytes
// int __thiscall processNotify(NotifyEvent* param_1, ulong param_2)
// ret 8 (2 params)
// FLAGS: default
//
// Attempt log:
// - Baseline used the canonical caller array fields and natural growth/copy loop;
//   the arithmetic dispatch lowered to cmp/jne and was four bytes too large.
// - A switch on mType reproduced the original subtract/je dispatch and shared tail.
// - The two notification calls are one-argument thiscall virtuals at +0xEC/+0xA4;
//   typed slot surfaces removed the incorrect extra fastcall register setup.
// - UnitAIModule owns the base vptr, so the derived subobject starts at +0x04;
//   removing the duplicate gap restored all proven array offsets and exact bytes.
// Main-agent audit restored destructor slots, qualified the base dispatch, and
// replaced manual allocation calls with natural new[]/delete[]; output remains exact.

#include <stdlib.h>

struct NotifyEvent {
    int caller;                  // +0x00
    char _gap_04[4];
    int mType;                   // +0x08
    char _gap_0C[4];
    int p2;                      // +0x10
};

class NotifySubObject {
public:
    virtual ~NotifySubObject(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58();
    virtual void notify(int value);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40();
    virtual void notifySelf(int value);
    int processNotify(NotifyEvent* evt, unsigned long param_2);
    void purgeNotifyQueue(unsigned long param_2);
};

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:
    NotifySubObject* sub;         // +0x04
    char _gap_08[0x58];
    int* caller_array;           // +0x60
    int caller_count;            // +0x64
    char _gap_68[4];
    int caller_capacity;         // +0x6C

    int processNotify(NotifyEvent* evt, unsigned long param_2);
};

int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* evt, unsigned long param_2)
{
    switch (evt->mType) {
    case 0x1F4:
    {
        if (evt->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }

        int caller = evt->caller;

    // Search for existing caller
    int i = 0;
    while (i < this->caller_count && i < this->caller_capacity) {
        if (this->caller_array[i] == caller)
            goto done;
        i++;
    }

    // Grow array if count >= capacity
    if (this->caller_count > this->caller_capacity - 1) {
        int new_cap = this->caller_count + 1;
        int* new_arr = new int[new_cap];
        if (new_arr) {
            int j;
            for (j = 0; j < this->caller_capacity && j < new_cap; j++)
                new_arr[j] = this->caller_array[j];
            delete[] this->caller_array;
            this->caller_array = new_arr;
            this->caller_capacity = new_cap;
        }
    }

        // Add caller to end of list
        this->caller_array[this->caller_count] = caller;
        this->caller_count++;

        goto done;
    }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(evt, param_2);
    }

done:
    // Notify sub via vtable+0xEC
    this->sub->notify(1);

    // Notify self via vtable+0xA4
    this->notifySelf(1);

    return 3;
}
