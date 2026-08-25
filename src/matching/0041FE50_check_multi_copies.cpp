// VA: 0041FE50 RGE_Base_Game::check_multi_copies (208 B)
// PDB source: basegame.cpp lines 3057-3095
// Baseline was a decompiler-shaped free-function lift with direct Win32 calls.
// The original uses the RGE_Prog_Info name/title fields, imported Win32 APIs,
// and the real check_prog_argument member.
// try 1: restore the period-plausible class/SDK surface and direct member fields;
//         expected to recover the 14 IAT calls and the +0xC/+0x20 layout.
// try 2: imported Win32/member reconstruction reached the correct calls and
//         fields but merged the failed-mutex cleanup with the lobby path.
// try 3: express ERROR_ALREADY_EXISTS as the positive guarded body; this keeps
//         the late failure release block and produces an exact 208-byte match.

extern "C" __declspec(dllimport) void* __stdcall FindWindowA(
    const char* class_name, const char* window_name);

#define s_LOBBY ((char*)0x58025C)



int RGE_Base_Game::check_multi_copies()
{
    this->prog_mutex = CreateMutexA(0, 1, this->prog_info->prog_name);
    if (GetLastError() == 0xB7) {
        void* window = FindWindowA(this->prog_info->prog_name,
                                   this->prog_info->prog_title);
        if (window != 0) {
            if (this->check_prog_argument(s_LOBBY) != 0) {
                SendMessageA(window, 0x10, 0, 0);
                if (this->prog_mutex != 0)
                    ReleaseMutex(this->prog_mutex);
                return 1;
            }
            if (IsIconic(window) != 0)
                ShowWindow(window, 1);
            SetForegroundWindow(window);
            BringWindowToTop(GetLastActivePopup(window));
        }

        if (this->prog_mutex != 0) {
            ReleaseMutex(this->prog_mutex);
            CloseHandle(this->prog_mutex);
            this->prog_mutex = 0;
        }
        return 0;
    }

    if (this->prog_mutex != 0)
        ReleaseMutex(this->prog_mutex);
    return 1;
}
