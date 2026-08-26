// 00420650 close_child_windows
//
// Attempt log:
// - Prior scratch hand-spelled an inline strcmp-like loop. Behavior was correct, but VC5 chose a different
//   register/loop family without EBX and with broad scheduling drift.
// - SpruceGlow MATCH: declare/use plain CRT `strcmp(str, s_Locate_Session) != 0`. Under the pinned VC5 /O2 flags,
//   this inlines to the original hand-unrolled strcmp loop using EDI hwnd, ESI literal pointer, EAX buffer pointer,
//   and EBX scratch.
// Result: MATCH locally with `python tools/check_function.py --va 00420650`.

extern "C" int __cdecl strcmp(const char* a, const char* b);

extern char s_Locate_Session[];

int __stdcall close_child_windows(void* hwnd, long param)
{
    char str[256];

    str[0] = 0;
    GetWindowTextA(hwnd, str, 0xff);

    if (strcmp(str, s_Locate_Session) != 0) {
        SendMessageA(hwnd, 0x10, 0, 0);
    }

    return 1;
}
