extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);


void RGE_Base_Game::close()
{
    PostMessageA(this->hwnd, 0x10, 0, 0);
}
