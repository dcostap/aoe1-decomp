// VA: 00422CC0 check_prog_argument (87B)
// Fixed buffer layout: 256 bytes, use buffer[4] form

extern "C" __declspec(dllimport) char* __stdcall CharUpperA(char* lpString);
extern "C" char* __cdecl strstr(const char* str, const char* substr);
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int count);



unsigned char RGE_Base_Game::check_prog_argument(char* param_1) {
    char buffer[256];

    strncpy(buffer, this->prog_info->cmd_line, 0xFF);
    buffer[0xFF] = 0;
    CharUpperA(buffer);
    if (strstr(buffer, param_1) != 0) {
        return 1;
    }
    return 0;
}
