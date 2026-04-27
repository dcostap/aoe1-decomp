// VA: 004FB160 TribeTacticalAIModule::taskWaterFisher (355 B)
// PDB source: taitacmd.cpp
// __thiscall, returns 0/1

extern void* MainDecisionAIModule_object(void* md, int id);
extern void* operator_new(unsigned int sz);
extern void operator_delete(void* p);

int TribeTacticalAIModule_taskWaterFisher(void* self, int player, float x, float y)
{
    void* obj = MainDecisionAIModule_object(*(void**)((char*)self + 0xF0), player);
    if (player == -1 || !obj)
        return 0;
    
    // Round position  
    int ix = (int)x;
    int iy = (int)y;
    
    // Call vtable method at +0x198 (distance/placement check)
    int (**vtable)(void);
    vtable = (int (**)(void))(*(int**)obj);
    int result = ((int (*)(void*, int, int, int, int, float, int, int, int))vtable[0x198/4])(obj, -1, -1, 1, 0, 1.0f, ix, iy, 1);
    if (!result)
        return 0;
    
    // Check/add to task list at +0xD58/+0xD5C/+0xD64
    {
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
    }
    return 1;
}
