class TChat {
public:
    char gap_00[0x04];
    int chatGroupPlayers[10];

    int inChatGroup(int index);
};

int TChat::inChatGroup(int index) {
    if (index >= 0) {
        if (index <= 9) {
            return chatGroupPlayers[index];
        }
    }
    return 0;
}
