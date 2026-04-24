typedef long (__stdcall *TRIBE_Game_WndProc)(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

class TRIBE_Game {
public:
    char gap_00[0xBF4];
    TRIBE_Game_WndProc old_video_wnd_proc;
    void stop_video(unsigned char do_stop);

    long video_wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
};

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* cursor);
extern "C" __declspec(dllimport) long __stdcall CallWindowProcA(TRIBE_Game_WndProc wndproc, void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

long TRIBE_Game::video_wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    switch (msg) {
    case 0x200:
        SetCursor(0);
        return 0;
    case 0x201:
    case 0x204:
        this->stop_video(1);
        return 0;
    }

    return CallWindowProcA(this->old_video_wnd_proc, hwnd, msg, wparam, lparam);
}
