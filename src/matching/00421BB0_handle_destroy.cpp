extern "C" __declspec(dllimport) int __stdcall KillTimer(void* hWnd, unsigned int idEvent);
extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode);

class RGE_Base_Game {
public:
    char gap_04[0x0C];
    void* prog_window;
    int prog_ready;
    char gap_18[0x2C];
    int is_timer;

    virtual int handle_destroy(void* param1, unsigned int param2, unsigned int param3, long param4);
};

int RGE_Base_Game::handle_destroy(void* param1, unsigned int param2, unsigned int param3, long param4) {
    this->prog_ready = 0;
    if (this->is_timer != 0) {
        KillTimer(this->prog_window, 1);
    }
    this->prog_window = 0;
    PostQuitMessage(0);
    return 1;
}
