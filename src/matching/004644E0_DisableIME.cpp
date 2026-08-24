extern void* AppWnd;
#ifndef AOE1_PANEL_CONTEXT_H
extern "C" void* __stdcall ImmAssociateContext(void* hwnd, void* imc);
#endif

#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    char gap_00[0xABC];
    unsigned long Imc;
    int ImeEnabled;

    void DisableIME(void);
};

#endif
void TPanelSystem::DisableIME(void) {
    if (ImeEnabled != 0) {
        Imc = ImmAssociateContext(AppWnd, 0);
        ImeEnabled = 0;
    }
}
