// VA: 005032E0 TribeTacticalAIModule::checkTradeBoats (406 B)
// PDB source: taitacmd.cpp
// __thiscall

extern void* operator_new(unsigned int sz);
extern void operator_delete(void* p);

int TribeTacticalAIModule_checkTradeBoats(void* self)
{
    int count = *(int*)((char*)self + 0x168);
    if (count <= 0)
        return 0;
    
    // Copy list from +0x164 (capacity +0x170)
    int* list = *(int**)((char*)self + 0x164);
    int cap = *(int*)((char*)self + 0x170);
    int i;
    
    // Check if we need to grow
    if (count > cap - 1) {
        int newCap = count + 1;
        int* newList = (int*)operator_new(newCap * 4);
        if (newList) {
            for (i = 0; i < cap && i < newCap; i++)
                newList[i] = list[i];
            operator_delete(list);
            *(int**)((char*)self + 0x164) = newList;
            *(int*)((char*)self + 0x170) = newCap;
            list = newList;
        }
    }
    
    // Find unused slot
    for (i = 0; i < count; i++) {
        if (list[i] >= 0) {
            // Check trade availability
            // ...
        }
    }
    
    // Handle trade boats
    // ...
    
    return 0;
}
