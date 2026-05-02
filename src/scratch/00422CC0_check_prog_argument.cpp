// VA: 00422CC0 check_prog_argument (87B)
// Fixed buffer layout: 256 bytes, use buffer[4] form

extern "C" char* __stdcall CharUpperA(char* lpString);
extern "C" char* __cdecl strstr(const char* str, const char* substr);
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int count);

class RGE_Prog_Info {
public:
    char gap_00[0x518];
    char cmd_line[256];
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;

    unsigned char check_prog_argument(char*);
};

unsigned char RGE_Base_Game::check_prog_argument(char* param_1) {
    char buffer[256];

    strncpy(&buffer[4], this->prog_info->cmd_line, 0xFF);
    buffer[0xFF] = 0;
    CharUpperA(buffer);
    if (strstr(buffer, param_1) != 0) {
        return 1;
    }
    return 0;
}
