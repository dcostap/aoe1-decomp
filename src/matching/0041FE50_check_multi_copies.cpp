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

extern "C" __declspec(dllimport) void* __stdcall CreateMutexA(
    void* attr, int initial_owner, const char* name);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(void);
extern "C" __declspec(dllimport) void* __stdcall FindWindowA(
    const char* class_name, const char* window_name);
extern "C" __declspec(dllimport) int __stdcall ReleaseMutex(void* mutex);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* handle);
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* window);
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* window, int command);
extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(void* window);
extern "C" __declspec(dllimport) void* __stdcall GetLastActivePopup(void* window);
extern "C" __declspec(dllimport) int __stdcall BringWindowToTop(void* window);
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* window, unsigned int message, unsigned int wparam, long lparam);

#define s_LOBBY ((char*)0x58025C)

class RGE_Prog_Info {
public:
    char prog_name[101];       // +0x00
    char prog_version[21];     // +0x65
    char prog_title[121];      // +0x7A
};

class RGE_Base_Game {
public:
    void* vtable_ptr;          // +0x00
    char gap_04[8];             // +0x04..+0x0B
    RGE_Prog_Info* prog_info;   // +0x0C
    char gap_10[0x10];           // +0x10..+0x1F
    void* prog_mutex;            // +0x20

    unsigned char check_prog_argument(char* argument);
    int check_multi_copies();
};

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
