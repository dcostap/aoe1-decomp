#ifndef TAITACMD_SHARED_CONTEXT
void __cdecl logCommonHistory(void* self_as_arg, const char* fmt, int groupId, int defenderId);

#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    int taskDefender(int groupId, int defenderId);
};

#endif
int TribeTacticalAIModule::taskDefender(int groupId, int defenderId) {
    logCommonHistory(this, "ERROR: Unused taskDefender call 1: defender ID=%d group=%d\n", groupId, defenderId);
    return 0;
}
#else
int TribeTacticalAIModule::taskDefender(int groupId, int defenderId) {
    return 0;
}
#endif
