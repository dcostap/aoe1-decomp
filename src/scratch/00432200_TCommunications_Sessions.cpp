// attempt 1: 96/134 bytes - VC5 optimized GUID struct assignment
// attempt 2: 96/134 - extern global didn't help
// attempt 3: compile error with volatile + non-volatile member call
// attempt 4: 134/134 but 49.3% diff - mov direct indexed vs lea base pointer for GUID copy
// attempt 5: same with pointer vars - VC5 still inlines access
// attempt 6: 128/134 - struct copy to locals shorter
// attempt 7: raw pointer arithmetic - same 49.3% diff
// BLOCKER: original uses 'lea ecx,[eax+0x12DC]' + 'add eax,0x12EC' for base pointers,
//   VC5 always generates 'mov ecx,[eax+0x12DC]' direct indexed access
//   Core logic correct: handler global, GetDPInterface, 2 GUID copies, SessionCount=0,
//   EraseInformation, Refresh. 11 diff spans all in GUID copy region.
//   Left in scratch per 10-probe rule.

struct GUID {
    unsigned int Data1;
    unsigned int Data2;
    unsigned int Data3;
    unsigned int Data4_0, Data4_1;
};

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
    char gap_04[0x257C];

public:
    TCommunications_Sessions(TCommunications_Handler* handler);
    void EraseInformation();
    int Refresh();
};

TCommunications_Sessions::TCommunications_Sessions(TCommunications_Handler* handler) {
    g_com_handler = handler;

    glpSERV = handler->GetDPInterface();

    unsigned int* sg = (unsigned int*)g_com_handler + 0x12DC / 4;
    gServGUID.Data1 = sg[0];
    gServGUID.Data2 = sg[1];
    gServGUID.Data3 = sg[2];
    gServGUID.Data4_0 = sg[3];
    gServGUID.Data4_1 = sg[4];

    unsigned int* ag = (unsigned int*)g_com_handler + 0x12EC / 4;
    gAppGUID.Data1 = ag[0];
    gAppGUID.Data2 = ag[1];
    gAppGUID.Data3 = ag[2];
    gAppGUID.Data4_0 = ag[3];
    gAppGUID.Data4_1 = ag[4];

    this->SessionCount = 0;
    EraseInformation();
    Refresh();
}
