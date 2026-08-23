// PDB-qualified owner: RGE_Comm_Error::NotifyWindowParam(COMMMESSAGES, long), com_err.cpp:12-15.
// BINARY NOTE: The function body is 00424E60-00424E94.  Do not claim the
// 00424E52+ padding/data between the constructor and this sibling, or the
// padding/data before ~RGE_Comm_Error at 00424EA0, as synthetic functions.

typedef int COMMMESSAGES;
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

class TDebuggingLog;
extern TDebuggingLog* L;
void Log(TDebuggingLog* log, char* fmt, int param1, long param2);

class RGE_Comm_Error {
public:
    void* HostHWND;

    void NotifyWindowParam(COMMMESSAGES msg, long param);
};

void RGE_Comm_Error::NotifyWindowParam(COMMMESSAGES msg, long param) {
    PostMessageA(HostHWND, 0x400, msg, param);
    Log(L, "COMM: Send msg to window WM_USER  Msg=%d  Param=%d\n", msg, param);
}
