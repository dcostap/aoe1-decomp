extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void* hWnd, const char* lpString);

class RGE_Base_Game {
public:
    char gap_0[0x10];
    void* hwnd; // offset 0x10
    char gap_14[0x3F0];
    char timing_string[1]; // offset 0x404

    void show_timings();
};

void RGE_Base_Game::show_timings()
{
    SetWindowTextA(this->hwnd, this->timing_string);
}
