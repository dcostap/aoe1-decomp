#ifndef COM_SESS_TU_CONTEXT
struct _GUID {
    char bytes[0x10];
};

struct SessionInfo {
    char Name[0x20];
    char gap_20[0x1F0];
    _GUID SessGUID;
    unsigned long CurrentPlayers;
    unsigned long MaxPlayers;
    char gap_228[0x10];
};

class TCommunications_Sessions {
public:
    int SessionCount;
    SessionInfo Session[1];

    _GUID* GetSessionGUID(int index);
};
#endif

_GUID* TCommunications_Sessions::GetSessionGUID(int index) {
    if ((index >= 0) && (index <= this->SessionCount)) {
        return &this->Session[index].SessGUID;
    }
    return 0;
}
