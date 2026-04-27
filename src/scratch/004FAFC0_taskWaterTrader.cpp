// VA: 004FAFC0 TribeTacticalAIModule::taskWaterTrader (410 B)
// PDB source: taitacmd.cpp
// __thiscall, returns 0/1

extern void* MainDecisionAIModule_object(void* md, int id);
extern void* operator_new(unsigned int sz);
extern void operator_delete(void* p);

int TribeTacticalAIModule_taskWaterTrader(void* self, int player, int targetPlayer)
{
    void* obj = MainDecisionAIModule_object(*(void**)((char*)self + 0xF0), player);
    if (player == -1 || !obj)
        return 0;
    
    void* targetObj = MainDecisionAIModule_object(*(void**)((char*)self + 0xF0), targetPlayer);
    if (!targetObj)
        return 0;
    
    // Get positions from target
    int tx = *(int*)((char*)targetObj + 0x38);
    int ty = *(int*)((char*)targetObj + 0x3C);
    int tz = *(int*)((char*)targetObj + 0x40);
    
    // Call vtable method at +0x198
    typedef int (*VtableMethod)(void*, int, int, int, int, int, float, int, int);
    VtableMethod vm = (VtableMethod)(*(int**)(obj))[0x198 / 4];
    int result = vm(obj, -1, -1, 1, 0, targetPlayer, 1.0f, tx, ty);
    if (!result)
        return 0;
    
    // Check/add to task list at +0xD58/+0xD5C/+0xD64
    int* list = *(int**)((char*)self + 0xD58);
    int count = *(int*)((char*)self + 0xD5C);
    int cap = *(int*)((char*)self + 0xD64);
    int i;
    
    for (i = 0; i < count && i < cap; i++) {
        if (list[i] == player)
            return 1;
    }
    
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
    return 1;
}
