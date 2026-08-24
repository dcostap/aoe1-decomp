#if !defined(COM_HAND_TU_CONTEXT)
typedef int COMMMESSAGES;
#endif // COM_HAND_TU_CONTEXT
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);

class TDebuggingLog;
#if !defined(COM_HAND_TU_CONTEXT)
extern TDebuggingLog* L;
#endif // COM_HAND_TU_CONTEXT
void Log(TDebuggingLog* log, char* fmt, int param1, long param2);

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x130C];
    void* HostHWND;

    void NotifyWindowParam(COMMMESSAGES msg, long param);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::NotifyWindowParam(COMMMESSAGES msg, long param) {
    PostMessageA(this->HostHWND, 0x400, msg, param);
    Log(L, "COMM: Send msg to window WM_USER  Msg=%d  Param=%d\n", msg, param);
}
