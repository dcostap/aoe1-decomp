class TDrawSystem {
public:
    void* gap_00;
    void* Wnd;

    int HandleQueryNewPalette(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
    void HandlePaletteChanged(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
};

void TDrawSystem::HandlePaletteChanged(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (hwnd != this->Wnd) {
        HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    }
}
