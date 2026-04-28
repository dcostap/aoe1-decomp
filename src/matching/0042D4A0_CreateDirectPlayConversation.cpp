// 0042D4A0 TCommunications_Handler::CreateDirectPlayConversation (Com_hand.cpp:5525-5568)
// Attempt 1

typedef struct _GUID {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
} GUID;

struct RGE_Comm_Error {
    void ShowReturn(long result, const char* msg);  // __thiscall
};

// TDebuggingLog::Log is variadic → __cdecl, this is pushed on stack as first arg
struct TDebuggingLog {
    void Log(const char* fmt, ...);
};

// COM interface structures
struct IDirectPlayVtbl {
    long (__stdcall *QueryInterface)(void*, const GUID*, void**);
    long (__stdcall *AddRef)(void*);
    long (__stdcall *Release)(void*);
};

struct IDirectPlay {
    IDirectPlayVtbl* lpVtbl;
};

// Global variables
extern "C" TDebuggingLog* L_global;         // 62C4FCh
extern "C" int g_DirectPlayConversation;     // 62C5ECh
extern "C" const GUID IID_IDirectPlay3A;    // 56F070h

// DirectPlayCreate (__stdcall via DPLAYX.DLL thunk)
long __stdcall DirectPlayCreate(void* lpGUID, void** lplpDP, void* pUnkOuter);

class TCommunications_Handler {
public:
    int OptionsChanged;               // +0x00
    char* OptionsData;                // +0x04
    int Steps;                        // +0x08
    char gap_0C[0x12D0];             // +0x0C to +0x12DB
    GUID ServiceGUID;                 // +0x12DC
    char gap_12EC[0x2C];             // +0x12EC to +0x1317
    GUID NullGUID;                    // +0x1318
    char gap_1328[0x1B8];            // +0x1328 to +0x14DF
    RGE_Comm_Error* Err;              // +0x14E0

    long CreateDirectPlayConversation();
};

long TCommunications_Handler::CreateDirectPlayConversation()
{
    void* lpIDC;
    long result;

    result = DirectPlayCreate(&this->ServiceGUID, &lpIDC, 0);
    this->Err->ShowReturn(result, "DPCreate");

    if (g_DirectPlayConversation) {
        L_global->Log("Already have conversation.");
        return 0x88770005;
    }

    if (result) {
        this->ServiceGUID = this->NullGUID;
        return result;
    }

    if (lpIDC) {
        long hr;
        
        hr = (*(long (__stdcall**)(void*, const GUID*, void**))(*(void**)lpIDC))(lpIDC, &IID_IDirectPlay3A, (void**)&g_DirectPlayConversation);
        
        if (hr) {
            L_global->Log("Get glpIDC returns...%ld", hr);
            return hr;
        }
        
        hr = (*(long (__stdcall**)(void*))((char*)(*(void**)lpIDC) + 8))(lpIDC);
        L_global->Log("Release: Links=%d", hr);
    }

    return 0;
}
