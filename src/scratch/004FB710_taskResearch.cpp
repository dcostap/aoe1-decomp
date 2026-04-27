// VA: 004FB710 TribeTacticalAIModule::taskResearch (448 B)
// PDB source: taitacmd.cpp
// __thiscall, returns 0/1

extern void* MainDecisionAIModule_object(void* md, int id);
extern void* RGE_Static_Object_unitAI(void* obj);
extern int UnitAIModule_type(void* ai);
extern int UnitAIModule_canResearch(void* ai, int techId);
extern void* operator_new(unsigned int sz);
extern void operator_delete(void* p);

int TribeTacticalAIModule_taskResearch(void* self, int player, int priority)
{
    if (!player) {
        // Log error
        return 0;
    }
    
    // Get research building
    typedef int (*FindFunc)(void*, int unitId1, int unitId2, int exclude);
    FindFunc findFn = (FindFunc)0x00408560;
    int buildingId = findFn((void*)player, 0x26B, 0x26C, -1);
    
    void* obj = MainDecisionAIModule_object(*(void**)((char*)self + 0xF0), buildingId);
    if (!obj)
        return 1;
    
    // Get unit AI module and check type
    void* ai = RGE_Static_Object_unitAI(obj);
    if (!ai)
        return 1;
    
    int type = UnitAIModule_type(ai);
    
    // Check what can be researched based on AI type
    if (UnitAIModule_canResearch(ai, type)) {
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
    }
    
    return 1;
}
