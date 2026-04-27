// first pass: default return is 1, fast-path palette message when in video mode, otherwise forward to the base helper
// tried direct if/else, explicit result+mode locals, and reordered forward-path temps; the remaining gap is the forward-call arg reload basin
// the fast-path palette branch is understood; pausing in scratch rather than churning the last push/register shape
class TRIBE_Game {
public:
    char pad_00[0x1B0];
    int game_mode;
    char pad_1B4[0xA38];
    void* video_window;       // +0xBEC
    char pad_BF0[0x1C];
    int video_hi_color;       // +0xC0C

    int handle_query_new_palette(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};

extern long (__stdcall *SendMessageA)(void* hWnd, unsigned int Msg, unsigned long wParam, long lParam);
extern int __stdcall RGE_Base_Game_handle_query_new_palette(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);

int TRIBE_Game::handle_query_new_palette(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    int result;
    int mode;
    void* p1;
    unsigned int p2;
    unsigned int p3;
    long p4;

    result = 1;
    mode = this->game_mode;
    if (mode == result) {
        if (this->video_window != 0 && this->video_hi_color == 0) {
            (*SendMessageA)(this->video_window, 0x476, 0, 0);
        }
    }
    else {
        p4 = param_4;
        p2 = param_2;
        p3 = param_3;
        p1 = param_1;
        result = RGE_Base_Game_handle_query_new_palette(p1, p2, p3, p4);
    }

    return result;
}
