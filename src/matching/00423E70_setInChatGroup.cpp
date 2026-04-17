class TChat {
public:
    char gap_00[0x04];
    int chatGroupPlayers[10];

    void setInChatGroup(int index, int value);
};

void TChat::setInChatGroup(int index, int value) {
    if (index > 0) {
        if (index <= 9) {
            chatGroupPlayers[index] = value;
        }
    }
}
