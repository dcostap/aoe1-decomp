// VA: 004FA000 TribeTacticalAIModule::taskRepairer (366 B)
// PDB source: taitacmd.cpp
// __thiscall, returns 0/1

extern void* RGE_Game_World_object(void* world, int id);
extern void* operator_new(unsigned int sz);
extern void operator_delete(void* p);

int TribeTacticalAIModule_taskRepairer(void* self, int player, int a2)
{
    // Get object from game world
    void* gameWorld = *(void**)(*(int*)((char*)self + 0xF0) + 0xF0);
    void* obj = RGE_Game_World_object(gameWorld, player);
    if (!obj)
        return 0;
    
    // Call vtable method at +0x194
    typedef int (*VtableMethod)(void*, int, int, int, int, float, int);
    VtableMethod vm = (VtableMethod)(*(int**)(obj))[0x194 / 4];
    int result = vm(obj, -1, -1, 1, 0, 1.0f, *(int*)((char*)a2 + 4));
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
