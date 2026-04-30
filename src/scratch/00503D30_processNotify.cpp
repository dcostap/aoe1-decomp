// 00503D30 TribeHuntedAnimalUnitAIModule::processNotify
// PDB: taiuaimd.cpp:99-136, 256 bytes
// int __thiscall processNotify(NotifyEvent* param_1, ulong param_2)
// ret 8 (2 params)
// FLAGS: default

#include <stdlib.h>

typedef unsigned long DWORD;

struct NotifyEvent {
    int caller;                  // +0x00
    char _gap_04[4];
    int mType;                   // +0x08
    char _gap_0C[4];
    int p2;                      // +0x10
};

// Forward declarations for CRT functions
void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

class UnitAIModule {
public:
    int processNotify(NotifyEvent* evt, unsigned long param_2);
    void purgeNotifyQueue(unsigned long param_2);
};

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:
    char _gap_00[4];
    void* sub;                   // +0x04
    char _gap_08[0x58];
    int* caller_array;           // +0x60
    int caller_count;            // +0x64
    char _gap_68[4];
    int caller_capacity;         // +0x6C

    int processNotify(NotifyEvent* evt, unsigned long param_2);
};

int TribeHuntedAnimalUnitAIModule::processNotify(NotifyEvent* evt, unsigned long param_2)
{
    // Cascading subtraction for switch
    int type = evt->mType - 0x1F4;
    if (type != 0) {
        if (type == 0x1B)
            return 2;
        return ((UnitAIModule*)this)->processNotify(evt, param_2);
    }

    // type == 0x1F4
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
        int* new_arr = (int*)operator_new(new_cap * 4);
        if (new_arr) {
            int j;
            for (j = 0; j < this->caller_capacity && j < new_cap; j++)
                new_arr[j] = this->caller_array[j];
            operator_delete(this->caller_array);
            this->caller_array = new_arr;
            this->caller_capacity = new_cap;
        }
    }

    // Add caller to end of list
    this->caller_array[this->caller_count] = caller;
    this->caller_count++;

done:
    // Notify sub via vtable+0xEC
    typedef void (__fastcall* NotifySub)(void*, int, int);
    (*((NotifySub*)((DWORD*)(*(DWORD*)this->sub) + 0xEC / 4)))(this->sub, 0, 1);

    // Notify self via vtable+0xA4
    typedef void (__fastcall* NotifySelf)(TribeHuntedAnimalUnitAIModule*, int, int);
    (*((NotifySelf*)((DWORD*)(*(DWORD*)this) + 0xA4 / 4)))(this, 0, 1);

    return 3;
}
