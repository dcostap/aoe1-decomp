#ifndef TAITACMD_SHARED_CONTEXT
void __cdecl logCommonHistory(void* self_as_arg, const char* fmt, int groupId, double x, double y);

#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    int taskDefender(int groupId, float x, float y);
};

#endif
int TribeTacticalAIModule::taskDefender(int groupId, float x, float y) {
    logCommonHistory(this, "ERROR: Unused taskDefender call 2: defender ID=%d to (%f, %f)\n", groupId, (double)x, (double)y);
    return 0;
}
#else
int TribeTacticalAIModule::taskDefender(int groupId, float x, float y) {
    return 0;
}
#endif
