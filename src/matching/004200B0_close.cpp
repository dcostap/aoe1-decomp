// STATUS: scratch
// FLAGS: config\flags\004200B0_close.rsp

extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

class RGE_Base_Game {
public:
    char gap_0[0x10];
    void* hwnd;

    void close();
};

void RGE_Base_Game::close()
{
    PostMessageA(this->hwnd, 0x10, 0, 0);
}
