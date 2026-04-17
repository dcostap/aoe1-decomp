extern void* AppWnd;
extern "C" void __stdcall ImmAssociateContext(void* hwnd, void* imc);

class TPanelSystem {
public:
    char gap_00[0xABC];
    void* Imc;
    int ImeEnabled;

    void EnableIME(void);
};

void TPanelSystem::EnableIME(void) {
    if (Imc != 0 && ImeEnabled == 0) {
        ImmAssociateContext(AppWnd, Imc);
    }
}
