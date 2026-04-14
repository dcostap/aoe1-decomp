void __cdecl debug_printf(const char*, ...);

struct TribeTacticalAIModule {
    char gap_0[0xF0];
    int mainDecisionAI;
};

void __fastcall taskDefender(TribeTacticalAIModule* self, int, int groupId, float x, float y, float z) {
    debug_printf("taskDefender %d %f %f %f\n", groupId, (double)x, (double)y, (double)z);
}
