extern "C" int __stdcall ImmSetOpenStatus(void* imc, int open);

class TPanelSystem {
public:
    char gap_00[0xABC];
    void* Imc;
    int ImeEnabled;
    int ImeOn;

    void TurnIMEOff(void);
};

void TPanelSystem::TurnIMEOff(void) {
    if (ImeOn != 0 && ImeEnabled != 0 && Imc != 0) {
        ImmSetOpenStatus(Imc, 0);
        ImeOn = 0;
    }
}
