// VA: 004FA940 TribeTacticalAIModule::taskExplorer (337 B)
// PDB source: taitacmd.cpp
// __thiscall, returns 0/1

extern void* operator_new(unsigned int sz);
extern void operator_delete(void* p);

int TribeTacticalAIModule_taskExplorer(void* self, int player)
{
    // Check if player already in explorer list at +0xD58/+0xD5C/+0xD64
    int* list = *(int**)((char*)self + 0xD58);
    int count = *(int*)((char*)self + 0xD5C);
    int cap = *(int*)((char*)self + 0xD64);
    int i;
    
    for (i = 0; i < count && i < cap; i++) {
        if (list[i] == player)
            goto append_done;
    }
    
    // Grow list if needed
    if (count > cap - 1) {
        int newCap = count + 1;
        int* newList = (int*)operator_new(newCap * 4);
        if (newList) {
            for (i = 0; i < cap && i < newCap; i++)
                newList[i] = list[i];
            operator_delete(list);
            *(int**)((char*)self + 0xD58) = newList;
            *(int*)((char*)self + 0xD64) = newCap;
            list = newList;
        }
    }
    
    list[count] = player;
    *(int*)((char*)self + 0xD5C) = count + 1;
    
append_done:
    // Check secondary list at +0xF8/+0x100
    int count2 = *(int*)((char*)self + 0xF8);
    int cap2 = *(int*)((char*)self + 0x100);
    int* list2 = *(int**)((char*)self + 0xFC);
    
    for (i = 0; i < count2 && i < cap2; i++) {
        if (list2[i] == player)
            return 1;
    }
    
    // Add to secondary list
    if (count2 > cap2 - 1) {
        int newCap = count2 + 1;
        int* newList = (int*)operator_new(newCap * 4);
        if (newList) {
            for (i = 0; i < cap2 && i < newCap; i++)
                newList[i] = list2[i];
            operator_delete(list2);
            *(int**)((char*)self + 0xFC) = newList;
            *(int*)((char*)self + 0x100) = newCap;
            list2 = newList;
        }
    }
    
    list2[count2] = player;
    *(int*)((char*)self + 0xF8) = count2 + 1;
    
    return 1;
}
