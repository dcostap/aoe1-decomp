extern "C" char* strcpy(char* dest, const char* src);

class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    unsigned int Me;
    char gap_10E4[0x1E4];
    char* FriendlyName;

    void SetMyPlayerName(char* name);
    void SetPlayerName(unsigned int player, char* name);
};

void TCommunications_Handler::SetPlayerName(unsigned int player, char* name) {
    if (player == this->Me) {
        this->SetMyPlayerName(name);
        return;
    }
    char* dest = this->FriendlyName + (player << 7);
    strcpy(dest, name);
}
