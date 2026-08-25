#ifndef TAITACMD_SHARED_CONTEXT
#ifndef TAITACMD_SHARED_CONTEXT
struct Inner3 {
    char gap_0[0x18];
    float age;       // 0x18
};

struct Inner2 {
    char gap_0[0x50];
    Inner3* ptr_50;  // 0x50
};

struct Inner1 {
    char gap_0[0xF0];
    Inner2* ptr_F0;  // 0xF0
};

struct TribeTacticalAIModule {
    char gap_0[0xF0];
    Inner1* mainDecisionAI;  // 0xF0
};

#endif
int TribeTacticalAIModule::inAge(int) {
    int currentAge = (int)self->mainDecisionAI->ptr_F0->ptr_50->age;
    return currentAge == age ? 1 : 0;
}
#else
int TribeTacticalAIModule::inAge(int) { return 0; }
#endif
