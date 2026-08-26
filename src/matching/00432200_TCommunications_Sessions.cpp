// VA: 00432200 TCommunications_Sessions::TCommunications_Sessions
// PDB: com_sess.cpp lines 19-35 (134 bytes, 33 asm lines)
// MATCH: `python tools/check_function.py --va 00432200` -> 0.0000%.
// Key fix 2026-05-19: model GUID as exactly 16 bytes and use natural whole-struct
// assignment for the two GUID copies. The prior 20-byte pseudo-GUID forced member
// loads from fixed offsets and blocked VC5's natural base-pointer copy sequence
// (`lea ecx,[eax+12DCh]` / `add eax,12ECh`).

#ifndef COM_SESS_TU_CONTEXT
struct GUID { unsigned int d[4]; };
struct IDirectPlay3 {};

extern IDirectPlay3* glpSERV;
extern GUID gServGUID, gAppGUID;

class TCommunications_Handler {
public:
    char gap_00[0x12DC];
    GUID ServiceGUID;
    GUID ApplicationGUID;

    IDirectPlay3* GetDPInterface();
};

TCommunications_Handler* g_com_handler;

class TCommunications_Sessions {
public:
    int SessionCount;

    TCommunications_Sessions(TCommunications_Handler* handler);

private:
    void EraseInformation();

public:
    int Refresh();
};
#endif

TCommunications_Sessions::TCommunications_Sessions(TCommunications_Handler* handler) {
    g_com_handler = handler;
    glpSERV = handler->GetDPInterface();
    gServGUID = g_com_handler->ServiceGUID;
    gAppGUID = g_com_handler->ApplicationGUID;
    this->SessionCount = 0;
    EraseInformation();
    Refresh();
}
