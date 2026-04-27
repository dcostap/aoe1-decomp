// VA: 0042F290
// RGE_Lobby::RGE_Lobby(void*)
// Source: com_loby.cpp lines 26-39

// attempt 1: natural constructor with new expression -> /GX + declared dtor triggers EH prolog
// attempt summary: first try used operator_new directly, no EH prolog (80 bytes)
// then switched to C++ new + declared ~RGE_Comm_Error() dtor + properly named /GX rsp -> EXACT MATCH
// FLAGS: /GX (needed for EH prolog basin; RGE_Comm_Error's declared dtor in different TU forces frame)

void* __cdecl operator_new(unsigned int size);

class RGE_Comm_Error {
public:
    void* HostHWND;
    long LastReportedError;

    RGE_Comm_Error(void* hwnd);
    ~RGE_Comm_Error();  // declared dtor forces /GX EH frame for new expression
};

class RGE_Lobby {
public:
    void* HostHWND;           // +0x00
    void* glpDPL;             // +0x04 IDirectPlayLobby*
    void* glpDPL2;            // +0x08 IDirectPlayLobby2*
    void* glpDP;              // +0x0C IDirectPlay2*
    void* glpdplConnection;   // +0x10 DPLCONNECTION*
    unsigned char lobby_game; // +0x14
    unsigned char _pad_0[3];  // +0x15 gap
    RGE_Comm_Error* Err;      // +0x18

    RGE_Lobby(void* hwnd);
};

RGE_Lobby::RGE_Lobby(void* hwnd) {
    this->HostHWND = hwnd;

    this->Err = new RGE_Comm_Error(hwnd);
    this->glpDP = 0;
    this->glpdplConnection = 0;
    this->glpDPL = 0;
    this->glpDPL2 = 0;
    this->lobby_game = 0;
}
