// 00420650 close_child_windows
// attempted natural strcmp-like source; current mismatch is register/loop shape.
// Need VC5 to keep hwnd in EDI, literal pointer in ESI, buffer pointer in EAX and emit hand-unrolled strcmp loop.
// HollowSnowdrop pass: tried pointer loop and indexed loop; best current is 126/126 bytes, 73.0% positional diff / 53.2% edit diff. Behavior correct but VC5 chooses no EBX and different strcmp family.

extern "C" int (__stdcall* const GetWindowTextA)(void* hwnd, char* text, int max_count);
extern "C" int (__stdcall* const SendMessageA)(void* hwnd, int msg, int wparam, int lparam);

extern char s_Locate_Session[];

extern "C" int __stdcall close_child_windows(void* hwnd, long param)
{
    char str[256];
    int cmp;

    str[0] = 0;
    GetWindowTextA(hwnd, str, 0xff);

    // strcmp(str, "Locate Session") source shape; VC5 currently picks a different but equivalent loop/register family.
    cmp = 0;
    for (int i = 0;; i += 2) {
        unsigned char a = str[i];
        unsigned char b = s_Locate_Session[i];
        if (a != b) { cmp = (a < b) ? -1 : 1; break; }
        if (a == 0) break;
        a = str[i + 1];
        b = s_Locate_Session[i + 1];
        if (a != b) { cmp = (a < b) ? -1 : 1; break; }
        if (a == 0) break;
    }

    if (cmp != 0) {
        SendMessageA(hwnd, 0x10, 0, 0);
    }
    return 1;
}
