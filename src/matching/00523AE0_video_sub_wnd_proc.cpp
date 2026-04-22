class TRIBE_Game {
public:
    long video_wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
};

extern TRIBE_Game* rge_base_game;

long __stdcall video_sub_wnd_proc(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    return rge_base_game->video_wnd_proc(hwnd, msg, wparam, lparam);
}
