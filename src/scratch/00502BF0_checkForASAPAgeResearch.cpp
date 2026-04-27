// VA: 00502BF0 TribeTacticalAIModule::checkForASAPAgeResearch (347 B)
// PDB source: taitacmd.cpp
// __thiscall

extern int AI_checkResearch(void* self, int age);
extern int BuildAIModule_canResearch(void* buildAI, int a, int b);
extern int BuildAIModule_popCount(void* buildAI);
extern int BuildAIModule_insertResearch(void* buildAI, int techId, int count, int flags);

int TribeTacticalAIModule_checkForASAPAgeResearch(void* self)
{
    // Check Dark Age research (age 1 -> 2)
    {
        int hasDark = AI_checkResearch(self, 1);
        if (hasDark && *(int*)((char*)self + 0x468) == 1) {
            void* buildAI = (char*)(*(int*)((char*)self + 0xF0)) + 0x104;
            if (BuildAIModule_canResearch(buildAI, 2, 1)) {
                int popCount = BuildAIModule_popCount(buildAI);
                if (popCount >= 0x1F4) {
                    if (BuildAIModule_insertResearch(buildAI, 0x65, 1, 4))
                        return 1;
                }
            }
        }
    }
    
    // Check Feudal Age research (age 2 -> 3)
    {
        int hasFeudal = AI_checkResearch(self, 2);
        if (hasFeudal && *(int*)((char*)self + 0x46C) == 1) {
            void* buildAI = (char*)(*(int*)((char*)self + 0xF0)) + 0x104;
            if (BuildAIModule_canResearch(buildAI, 3, 1)) {
                int popCount = BuildAIModule_popCount(buildAI);
                if (popCount >= 0x320) {
                    if (BuildAIModule_insertResearch(buildAI, 0x66, 1, 4))
                        return 1;
                }
            }
        }
    }
    
    return 0;
}
