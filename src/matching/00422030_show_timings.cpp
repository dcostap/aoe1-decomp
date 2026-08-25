extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void* hWnd, const char* lpString);

void RGE_Base_Game::show_timings()
{
    SetWindowTextA(this->hwnd, this->timing_text);
}
