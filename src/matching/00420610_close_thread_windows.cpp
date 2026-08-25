
extern void* AppWnd;

int __stdcall close_thread_windows(void* wnd, long unused) {
    if (wnd != AppWnd) {
        if (GetParent(wnd) != AppWnd) {
            SendMessageA(wnd, 0x10, 0, 0);
        }
    }
    return 1;
}
