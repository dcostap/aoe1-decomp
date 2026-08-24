#ifndef AOE1_PANEL_CONTEXT_H
extern "C" int __stdcall ImmSetOpenStatus(void* imc, int open);
#endif

#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    char gap_00[0xABC];
    unsigned long Imc;
    int ImeEnabled;
    int ImeOn;

    void TurnIMEOn(void);
};

#endif
void TPanelSystem::TurnIMEOn(void) {
    if (ImeOn == 0 && ImeEnabled != 0 && Imc != 0) {
        ImmSetOpenStatus(Imc, 1);
        ImeOn = 1;
    }
}
