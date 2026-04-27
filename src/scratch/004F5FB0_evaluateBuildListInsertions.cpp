// VA: 004F5FB0 TribeTacticalAIModule::evaluateBuildListInsertions (327 B)
// PDB source: taitacmd.cpp
// __thiscall, void

extern int BuildAIModule_haveBuildList(void* buildAI);
extern int BuildAIModule_insert(void* buildAI, int unitId, int count, int flags);
extern int BuildAIModule_count(void* buildAI);
extern int TribeTacticalAIModule_insert(void* self, int unitId, int count, int flags);

void TribeTacticalAIModule_evaluateBuildListInsertions(void* self)
{
    int isActive = *(int*)((char*)self + 0x4C8);
    
    if (isActive == 1) {
        void* buildAI = (char*)(*(int*)((char*)self + 0xF0)) + 0x104;
        if (BuildAIModule_haveBuildList(buildAI)) {
            if (!*(int*)((char*)self + 0xF88)) {
                int popCount = *(int*)(*(int*)((char*)self + 0xF0) + 0x124C);
                int threshold = *(int*)((char*)self + 0x438);
                if (popCount >= threshold) {
                    BuildAIModule_insert(buildAI, 0x67, 1, 0);
                    *(int*)((char*)self + 0xF88) = 1;
                }
            }
        }
    }
    
    if (isActive == 1) {
        void* buildAI = (char*)(*(int*)((char*)self + 0xF0)) + 0x104;
        if (BuildAIModule_haveBuildList(buildAI)) {
            if (!*(int*)((char*)self + 0xF8C) && !*(int*)((char*)self + 0xF88)) {
                int insertId = *(int*)((char*)self + 0x450);
                if (insertId != -1) {
                    BuildAIModule_insert(buildAI, insertId, 1, 0);
                    *(int*)((char*)self + 0x450) = -1;
                }
            }
        }
    }
    
    TribeTacticalAIModule_insert(self, 0x32, 1, 0);
    TribeTacticalAIModule_insert(self, 0x4F, 1, 0);
}
