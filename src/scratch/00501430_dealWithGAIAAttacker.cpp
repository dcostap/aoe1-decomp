// VA: 00501430 TribeTacticalAIModule::dealWithGAIAAttacker (424 B)
// PDB source: taitacmd.cpp
// __thiscall

extern void* TacticalAIGroup_get(void* self, int idx);

int TribeTacticalAIModule_dealWithGAIAAttacker(void* self, int* attackerList, int attackerCount)
{
    if (!attackerList || !attackerCount)
        return 0;
    
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x108) && i < *(int*)((char*)self + 0x110); i++) {
        void* group = TacticalAIGroup_get(*(void**)((char*)self + 0x104), i);
        if (!group)
            continue;
        
        // Check if this group is already tracking the attacker
        int groupTarget = *(int*)((char*)group + 4);
        int j;
        for (j = 0; j < attackerCount; j++) {
            if (groupTarget == attackerList[j])
                goto found;
        }
        
        // Check distance to attacker
        // ...
        
        found:;
    }
    
    // Process attacker
    // ...
    
    return 0;
}
