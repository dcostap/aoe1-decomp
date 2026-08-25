extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_ai(void) {
    char str[256];
    sprintf(str, "No AI Information for Player #%d.",
            (int)this->world->curr_player);
    SetWindowTextA(this->prog_window, str);
}
