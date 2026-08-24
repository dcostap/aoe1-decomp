extern "C" int __cdecl sprintf(char*, const char*, ...);

class TCommunications_Handler_sgt {
public:
    int SetGameTitle(const char* title);
    char gap_00[0x10F8];
    char game_name[0x102];
    char player_name[1];
};


int TCommunications_Handler_sgt::SetGameTitle(const char* title) {
    sprintf(this->player_name, "%s [%s]", title, this->game_name);
    return 1;
}
