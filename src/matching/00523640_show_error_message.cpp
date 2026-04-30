// 00523640 TRIBE_Game::show_error_message
// tribegam.cpp:1206-1211, 96 bytes, __thiscall

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

class TRIBE_Game {
public:
    // vt[0..7] padding (implicit vtable at +0x00)
    virtual void pad00() = 0;
    virtual void pad01() = 0;
    virtual void pad02() = 0;
    virtual void pad03() = 0;
    virtual void pad04() = 0;
    virtual void pad05() = 0;
    virtual void pad06() = 0;
    virtual void pad07() = 0;
    // vt[8] = +0x20
    virtual void load_string(int id, char* buf, int len) = 0;
    // vt[9] padding
    virtual void pad09() = 0;
    // vt[10] = +0x28
    virtual void load_string2(int a, int b, int c, char* buf, int len) = 0;
    
    unsigned char gap_04[0x0C];
    void* field_10;  // +0x10, HWND or similar
    void show_error_message(int param_1);
};

void TRIBE_Game::show_error_message(int param_1) {
    char title[256];
    char msg[256];
    this->load_string(0xFA8, title, 256);
    this->load_string2(1, param_1, 0, msg, 256);
    MessageBoxA((void*)this->field_10, msg, title, 0x10);
}
