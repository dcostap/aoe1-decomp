#ifndef COM_SESS_TU_CONTEXT
extern "C" void* __cdecl memset(void* dest, int val, unsigned int count);
struct EraseSessionRecord {
    char bytes[0x238];
};
class TCommunications_Sessions {
public:
    void EraseInformation();
    int SessionCount;
    EraseSessionRecord Session[501];
};
#endif
void TCommunications_Sessions::EraseInformation() {
    SessionCount = 0;
    memset(Session, 0, sizeof(Session));
}
