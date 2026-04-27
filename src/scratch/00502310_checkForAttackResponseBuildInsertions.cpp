// VA: 00502310 TribeTacticalAIModule::checkForAttackResponseBuildInsertions (321 B)
// PDB source: taitacmd.cpp
// __thiscall, EH-framed, time-based attack response insertion

extern int BuildAIModule_have(void* buildAI, int a, int b, int c);
extern int BuildAIModule_insert(void* buildAI, int unitId, int count, int flags);
extern int AI_GameTime(void* gameWorld);

int TribeTacticalAIModule_checkForAttackResponseBuildInsertions(void* self)
{
    void* gameWorld = *(void**)(*(int*)((char*)self + 0xF0) + 0xF0);
    int gameTime = AI_GameTime(gameWorld);
    int lastAttackTime = *(int*)((char*)self + 0xF94);
    int elapsed = gameTime - lastAttackTime;
    
    // Check if enough time passed
    if (elapsed < 180)
        return 0;
    
    // Insert attack response units
    // BuildAIModule_insert(*(void**)((char*)self + 0xF0), 0x67, 0, 0);
    // ...
    
    return 1;
}
