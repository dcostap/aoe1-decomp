// VA: 004FB9E0 TribeTacticalAIModule::taskTransporter (336 B)
// PDB source: taitacmd.cpp
// __thiscall, returns 0/1

extern void* MainDecisionAIModule_object(void* md, int id);
extern float RGE_Static_Object_distance_to_position(void* obj, float x, float y, float z);
extern void* operator_new(unsigned int sz);
extern void operator_delete(void* p);
extern void* operator_new_array(unsigned int sz);

int TribeTacticalAIModule_taskTransporter(void* self, int player, float x, float y)
{
    void* obj = MainDecisionAIModule_object(*(void**)((char*)self + 0xF0), player);
    if (player == -1 || !obj)
        return 0;
    
    float dist = RGE_Static_Object_distance_to_position(obj, x, y, 1.0f);
    int threshold = *(int*)&dist;
    
    // Check if player already in transport list
    int* list = *(int**)((char*)self + 0xD58);
    int count = *(int*)((char*)self + 0xD5C);
    int cap = *(int*)((char*)self + 0xD64);
    int i;
    
    for (i = 0; i < count && i < cap; i++) {
        if (list[i] == player)
            goto found;
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
    
found:
    // Call vtable task method
    typedef int (*TaskFunc)(void*, int, int, float, float, int, int, int);
    void* gameWorld = *(void**)(*(int*)((char*)self + 0xF0) + 0xF0);
    TaskFunc taskFn = (TaskFunc)(*(int**)(gameWorld))[0x30 / 4];
    return taskFn(gameWorld, *(short*)((char*)gameWorld + 0x4A), player, 1.0f, 1.0f, player, -1, 0x2CA);
}
