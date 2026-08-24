// 00429810 TCommunications_Handler::SendChatMsg
// Size: 90 bytes, diff: 13 bytes (14.44%) initially, improved but not exact
//
// Discoveries:
// 1. Original passes destMap (not destMap+4) to TXChat — Ghidra decompiler was wrong
// 2. Original writes destMap[to] = 'Y' (not destMap[to+8]) — Ghidra decompiler was wrong
// 3. Remaining diff: VC5 scheduling/register allocation for lea between constant stores
//    Original interleaves lea between mov [esp+10h] and mov [esp+14h]:
//      mov [esp+10h], ecx; lea edx,[esp+10h]; mov [esp+14h], ecx
//    Rebuilt does both stores first, then lea:
//      mov [esp+10h], eax; mov [esp+14h], eax; lea eax,[esp+10h]
//    This also shifts displacements (1Ch vs 20h/24h) for destMap[8] and destMap[to] stores.

#if !defined(COM_HAND_TU_CONTEXT)
extern void* L;
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
void __cdecl Log(void* log, const char* fmt, unsigned int p1, unsigned int p2, const char* p3);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    void SendChatMsg(unsigned int player, unsigned int to, const char* text);
    long TXChat(unsigned int player, const unsigned char* destMap, const char* text);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::SendChatMsg(unsigned int player, unsigned int to, const char* text) {
    void* log = L;
    unsigned char destMap[10];

    Log(log, "SendChatMsg FROM=%d  TO=%d Text='%s'", player, to, text);
    *(unsigned int*)&destMap[0] = 0x4E4E4E4E;
    *(unsigned int*)&destMap[4] = 0x4E4E4E4E;
    destMap[8] = (unsigned char)0x4E;
    destMap[to] = 'Y';
    TXChat(player, destMap, text);
}
