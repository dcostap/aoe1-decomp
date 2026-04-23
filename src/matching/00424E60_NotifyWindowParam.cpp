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
    PostMessageA(this->HostHWND, 0x400, msg, param);
    Log(L, "COMM: Send msg to window WM_USER  Msg=%d  Param=%d\n", msg, param);
}
