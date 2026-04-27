// SendChatMsg (00429810, 90 bytes, Com_hand.cpp)
// Attempt 4: 10-byte array, ecx fill

extern void* L;

void __cdecl Log(void* log, const char* fmt, unsigned int p1, unsigned int p2, const char* p3);

class TCommunications_Handler {
public:
    void SendChatMsg(unsigned int player, unsigned int to, const char* text);
    long TXChat(unsigned int player, const unsigned char* destMap, const char* text);
};

void TCommunications_Handler::SendChatMsg(unsigned int player, unsigned int to, const char* text) {
    void* log = L;
    unsigned char destMap[10];

    Log(log, "SendChatMsg FROM=%d  TO=%d Text='%s'", player, to, text);
    *(unsigned int*)&destMap[0] = 0x4E4E4E4E;
    *(unsigned int*)&destMap[4] = 0x4E4E4E4E;
    destMap[8] = (unsigned char)0x4E;
    destMap[to + 8] = 'Y';
    TXChat(player, destMap + 4, text);
}
