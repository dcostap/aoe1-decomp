extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_comm(void) {
    char str[256];
    sprintf(str, "%s", this->comm_handler->GetCommInfo(1));
    SetWindowTextA(this->prog_window, str);
}
