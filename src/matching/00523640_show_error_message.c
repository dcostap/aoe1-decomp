// attempt 1: C++ method-shaped translation in a .c file, with /TP forced in the rsp
// goal: keep the 256-byte title/msg frame, the two virtual loads, and the MessageBoxA IAT tail
// attempt 2: removed the explicit object-field placeholder so the real window member lands at +0x10

class TRIBE_Game {
public:
    char gap_0[0xC];
    void* window; // +0x10

    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int string_id, char* title, int len);
    virtual void vf24();
    virtual void vf28(int one, int param_1, int zero, char* msg, int len);

    void show_error_message(int param_1);
};

extern int (__stdcall *MessageBoxA)(void* hwnd, char* text, char* caption, unsigned int type);

void TRIBE_Game::show_error_message(int param_1) {
    char title[256];
    char msg[256];

    this->vf20(0xFA8, title, 0x100);
    this->vf28(1, param_1, 0, msg, 0x100);
    MessageBoxA(this->window, msg, title, 0x10);
}
