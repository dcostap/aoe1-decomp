// VA: 004211D0 RGE_Base_Game::handle_key_down (268 B)
// PDB source: basegame.cpp
// Packet-grounded: check prog_ready, record key state, dispatch to panel/renderer

extern short GetKeyState(int vkey);
extern int IsIconic(void* hwnd);
extern int TDrawArea_take_snapshot(void* da, const char* fmt, int* counter);

int g_keydown_shift = 0;       // 5B2368
int g_keydown_ext = 0;         // 5B2370
int g_ctrl_state = 0;          // 62C4BC
int g_alt_state = 0;           // 62C4B4
int g_shift_state = 0;         // 5B2164
int snapshot_counter = 1;      // 57FA08

struct Shim_211D0 {
    void* vtable;              // +0x00
    char p4[0x0C - 4];
    void* prog_info;           // +0x0C
    int prog_ready;            // +0x14
    char p18[0x48 - 0x18];
    void* draw_system;         // +0x48
};

int RGE_Base_Game_handle_key_down(Shim_211D0* self, void* hwnd, unsigned int msg, unsigned int wparam, long lparam)
{
    short s;
    int (*vfn)(void*, int, int, int, int, int);
    
    if (self->prog_ready == 0)
        return 1;
    
    g_keydown_shift = wparam;
    g_keydown_ext = lparam & 0xFFFF;
    
    s = GetKeyState(0x11);  // VK_CONTROL
    g_ctrl_state = (s < 0) ? 1 : 0;
    
    s = GetKeyState(0x12);  // VK_MENU
    g_alt_state = (s < 0) ? 1 : 0;
    
    s = GetKeyState(0x10);  // VK_SHIFT
    g_shift_state = (s < 0) ? 1 : 0;
    
    if (hwnd == self->prog_info && msg == 0x104) {
        if (g_keydown_shift == 0x12 || g_keydown_shift == 0x20 || g_keydown_shift == 0x79) {
            if (*(int*)((char*)self->prog_info + 0x894) != 0) {
                if (!IsIconic(hwnd))
                    return 0;
            }
        }
    }
    
    if (g_ctrl_state && g_keydown_shift == 0x7B) {
        TDrawArea_take_snapshot(
            *(void**)((char*)self->draw_system + 0x0C),
            ".\\AoE%04d.bmp",
            &snapshot_counter);
        return 0;
    }
    
    vfn = (int(*)(void*, int, int, int, int, int))((int*)self)[0x100/4];
    {
        int result = vfn(self, g_keydown_shift, g_keydown_ext, g_ctrl_state, g_alt_state, g_shift_state);
        return (result < 0) ? 0 : 1;
    }
}
