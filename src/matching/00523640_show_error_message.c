// 00523640 TRIBE_Game::show_error_message
// tribegam.cpp:1206-1211, 96 bytes, __thiscall

class TRIBE_Game {
public:
    void* vtable;
    unsigned char gap_04[0x0C];
    void* field_10;  // +0x10, HWND or similar
    void show_error_message(int param_1);
    void load_string(int id, char* buf, int len) { (*(void(__thiscall**)(TRIBE_Game*, int, char*, int))((void**)this)[8])(this, id, buf, len); }
    void load_string2(int a, int b, int c, char* buf, int len) { (*(void(__thiscall**)(TRIBE_Game*, int, int, int, char*, int))((void**)this)[10])(this, a, b, c, buf, len); }
};

void TRIBE_Game::show_error_message(int param_1) {
    char title[256];
    char msg[256];
    this->load_string(0xFA8, title, 256);
    this->load_string2(1, param_1, 0, msg, 256);
    MessageBoxA((HWND)this->field_10, msg, title, 0x10);
}
