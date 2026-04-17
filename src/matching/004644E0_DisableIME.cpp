extern void* AppWnd;
extern "C" void* __stdcall ImmAssociateContext(void* hwnd, void* imc);

class TPanelSystem {
public:
    char gap_00[0xABC];
    void* Imc;
    int ImeEnabled;

    void DisableIME(void);
};

void TPanelSystem::DisableIME(void) {
    if (ImeEnabled != 0) {
        Imc = ImmAssociateContext(AppWnd, 0);
        ImeEnabled = 0;
    }
}
