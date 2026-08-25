#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
typedef unsigned long ulong;

#endif
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    int storeAttackMemory(int param_1, int param_2, int param_3, int param_4,
                          int param_5, int param_6, int param_7, ulong param_8,
                          int param_9, int param_10, int param_11);

    int storeAttackMemory(int param_1, int param_2, int param_3, int param_4,
                          int param_5, int param_6, int param_7, ulong param_8,
                          int param_9);
};
#endif

#endif
int TribeInformationAIModule::storeAttackMemory(int param_1, int param_2, int param_3, int param_4,
                                                int param_5, int param_6, int param_7, ulong param_8,
                                                int param_9) {
    return this->storeAttackMemory(param_1, param_2, param_3, param_2, param_3,
                                   param_4, param_5, param_6, param_7, param_8, param_9);
}
