extern int __cdecl __ftol(void);

struct TribeTacticalAIModule {
    char gap_0[0xF0];
    int mainDecisionAI;
};

int __stdcall getCurrentAge(int);

int __fastcall inAge(TribeTacticalAIModule* self, int, int age) {
    int currentAge = getCurrentAge(self->mainDecisionAI);
    if (currentAge == age)
        return 1;
    return 0;
}
