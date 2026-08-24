extern "C" char* strcpy(char* dest, const char* src);

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    unsigned int Me;
    char gap_10E4[0x1E4];
    char* FriendlyName;

    void SetMyPlayerName(char* name);
    void SetPlayerName(unsigned int player, char* name);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SetPlayerName(unsigned int player, char* name) {
    if (player == this->Me) {
        this->SetMyPlayerName(name);
        return;
    }
    char* dest = this->FriendlyName[player].Text;
    strcpy(dest, name);
}
