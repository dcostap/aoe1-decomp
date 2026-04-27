// VA: 00500670 TribeTacticalAIModule::readyAndIdleGroup (317 B)
// PDB source: taitacmd.cpp
// __thiscall, iterate group linked list, find best group near position

extern int TacticalAIGroup_type(void* group);
extern int TacticalAIGroup_desiredNumberUnits(void* group);
extern int TacticalAIGroup_numberUnits(void* group);
extern void* TacticalAIGroup_position(void* group);
extern int sqrt_int(int val);

void* TribeTacticalAIModule_readyAndIdleGroup(void* self, int type, int maxDist, int targetX, int targetY)
{
    void* bestGroup = 0;
    int bestDist = 0x7FFFFFFF;
    
    void* head = *(void**)((char*)self + 0x9D4);
    void* current = *(void**)((char*)self + 0x9D8);
    void* listEnd = (void*)((char*)self + 0x9D4); // sentinel address
    
    int bG = 0;
    
    while (current != listEnd && current != 0) {
        // Check group type match
        if (type != -1) {
            if (TacticalAIGroup_type(current) != type)
                goto next;
        }
        
        // Check if desired units <= actual units
        {
            int desired = TacticalAIGroup_desiredNumberUnits(current);
            int actual = TacticalAIGroup_numberUnits(current);
            if (desired > actual)
                goto next;
        }
        
        // Get attacker module and check distance
        {
            void* pos = TacticalAIGroup_position(current);
            int dx = *(int*)((char*)pos + 4) - targetX;
            int dy = *(int*)((char*)pos + 4) - targetY;
            int distSq = dx * dx + dy * dy;
            int dist = sqrt_int(distSq);
            
            if (maxDist != -1 && dist >= maxDist)
                goto next;
            if (dist >= bestDist)
                goto next;
            
            bestGroup = current;
            bestDist = dist;
        }
        
        next:
        current = *(void**)((char*)current + 4);
    }
    
    return bestGroup;
}
