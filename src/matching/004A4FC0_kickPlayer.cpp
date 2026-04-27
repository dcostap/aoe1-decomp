// first pass: straight stack-buffer helper with the comm/name/string calls in packet order
// if this sticks, the remaining work is likely just the exact local-buffer and call-site shape
class TCommunications_Handler {
public:
    char* GetPlayerName(unsigned int player);
};

extern TCommunications_Handler* comm;
extern "C" int sprintf(char* buffer, const char* format, ...);

class TEasy_Panel {
public:
    char* get_string(int string_id);
    void popupYesNoDialog(char* text, char* caption, int param_3, int param_4);
};

class TribeMPSetupScreen : public TEasy_Panel {
public:
    char pad_00[0x724];
    int playerToKick;

    void kickPlayer(int param_1);
};

void TribeMPSetupScreen::kickPlayer(int param_1) {
    char text[256];

    this->playerToKick = param_1;
    sprintf(text, this->get_string(0x25C8), comm->GetPlayerName((unsigned int)param_1));
    this->popupYesNoDialog(text, (char*)0x5867E8, 0x1C2, 0x64);
}
