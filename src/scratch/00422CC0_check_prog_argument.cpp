// quick-win attempt log:
// no existing work file for 00422CC0; the helper is a tiny string search over a
// stack cmd-line buffer built from prog_info->cmd_line
// tried the literal copy/upper/search flow, then buffer-layout probes (256-byte array,
// struct wrapper, and shorter array variants)
// remaining mismatch is localized to the first stack-buffer address: VC5 keeps
// emitting the copy destination 4 bytes too far into the local frame

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
    char cmd_line[252];
    char* found;

    strncpy(cmd_line + 4, this->prog_info->cmd_line, 0xFF);
    cmd_line[251] = 0;
    CharUpperA(cmd_line);
    found = strstr(cmd_line, param_1);
    if (found == 0) {
        return 0;
    }
    return 1;
}
