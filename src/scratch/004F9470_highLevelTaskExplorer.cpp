// VA: 004F9470 TribeTacticalAIModule::highLevelTaskExplorer (314 B)
// PDB source: taitacmd.cpp
// __thiscall, returns 0/1 based on explorer unit checks

extern void* RGE_Game_World_object(void* world, int id);
extern void* RGE_Static_Object_unitAI(void* obj);
extern int UnitAIModule_type(void* ai);
extern int UnitAIModule_check(void* ai, int type);
extern int TribeTacticalAIModule_taskExplorer(void* self, int player, int a2);

int TribeTacticalAIModule_highLevelTaskExplorer(void* self, int player)
{
    void* gameWorld = *(void**)(*(int*)((char*)self + 0xF0) + 0xF0);
    void* obj = RGE_Game_World_object(gameWorld, player);
    if (!obj)
        return 0;
    
    void* ai = RGE_Static_Object_unitAI(obj);
    if (!ai)
        return 0;
    
    int aiType = UnitAIModule_type(ai);
    
    // Check for specific explorer-like types (0x258, 0x25A, 0x26A, 0x25D)
    if (aiType == 0x258 || aiType == 0x25A || aiType == 0x26A || aiType == 0x25D)
        return 1;
    
    // Check if unit has been away long enough
    float distDone = *(float*)((char*)self + 0x44);
    if (*(int*)&distDone < 0x3F800000) // compare against 1.0f
        return 0;
    
    // Check unit type match
    if (UnitAIModule_type(ai) == 0x2C6 && UnitAIModule_check(ai, 100) == 100)
        return 0;
    if (UnitAIModule_type(ai) == 0x2BE)
        return 0;
    
    // Check can handle task
    if (UnitAIModule_check(ai, 0x2C1) == 1)
        return 0;
    
    // Call taskExplorer
    return TribeTacticalAIModule_taskExplorer(self, player, player);
}
