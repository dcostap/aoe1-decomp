#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
typedef unsigned long ulong;

#endif
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    int storeAttackMemory(unsigned char param_1, unsigned char param_2,
                          unsigned char param_3, unsigned char param_4,
                          unsigned char param_5, short param_6,
                          unsigned char param_7, ulong param_8, int param_9);
};
#endif

#endif
int TribeInformationAIModule::storeAttackMemory(
    unsigned char param_1, unsigned char param_2, unsigned char param_3,
    unsigned char param_4, unsigned char param_5, short param_6,
    unsigned char param_7, ulong param_8, int param_9) {
    return this->storeAttackMemory(param_1, param_2, param_3, param_2, param_3,
                                   param_4, param_5, param_6, param_7, param_8,
                                   param_9);
}
