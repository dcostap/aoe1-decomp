// VA: 005004C0 TribeTacticalAIModule::bestGroup (430 B)
// PDB source: taitacmd.cpp
// __thiscall, returns best group pointer

extern int TacticalAIGroup_type(void* group);
extern int TacticalAIGroup_subtype(void* group);
extern int TacticalAIGroup_desiredNumberUnits(void* group);
extern int TacticalAIGroup_numberUnits(void* group);

void* TribeTacticalAIModule_bestGroup(void* self, int type, int subtype, int a3)
{
    void* bestGroup = 0;
    int bestScore = -1;
    
    void* head = *(void**)((char*)self + 0x9D4);
    void* current = *(void**)((char*)self + 0x9D8);
    void* listEnd = (void*)((char*)self + 0x9D4);
    
    while (current != listEnd && current != 0) {
        // Check type
        if (type != -1 && TacticalAIGroup_type(current) != type)
            goto next;
        
        // Check subtype
        if (subtype != -1 && TacticalAIGroup_subtype(current) != subtype)
            goto next;
        
        // Check desired vs actual units  
        {
            int desired = TacticalAIGroup_desiredNumberUnits(current);
            int actual = TacticalAIGroup_numberUnits(current);
            if (desired > actual)
                goto next;
            
            // Evaluate group score
            {
                int score = desired - actual;
                if (score > bestScore) {
                    bestScore = score;
                    bestGroup = current;
                }
            }
        }
        
        next:
        current = *(void**)((char*)current + 4);
    }
    
    return bestGroup;
}
