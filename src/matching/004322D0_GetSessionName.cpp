#ifndef COM_SESS_TU_CONTEXT
struct SessionInfo {
    char Name[0x20];
    char gap_20[0x218];
};

class TCommunications_Sessions {
public:
    int SessionCount;
    SessionInfo Session[1];

    char* GetSessionName(int index);
};
#endif

char* TCommunications_Sessions::GetSessionName(int index) {
    if ((index >= 0) && (index <= this->SessionCount)) {
        return this->Session[index].Name;
    }
    return 0;
}
