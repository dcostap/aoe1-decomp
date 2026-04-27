// VA: 0041FE50 RGE_Base_Game::check_multi_copies (208 B)
// PDB source: basegame.cpp
// Packet-grounded: CreateMutexA + FindWindowA + activate/close

extern void* CreateMutexA(void* attr, int init, const char* name);
extern int GetLastError(void);
extern int FindWindowA(const char* cls, const char* win);
extern int ReleaseMutex(void* m);
extern int CloseHandle(void* h);
extern int IsIconic(void* hw);
extern int ShowWindow(void* hw, int cmd);
extern int SetForegroundWindow(void* hw);
extern unsigned long GetLastActivePopup(void* hw);
extern int BringWindowToTop(unsigned long hw);
extern int SendMessage(void* hw, unsigned int msg, unsigned int wp, long lp);
extern int check_prog_arg(void* self, const char* arg);

struct Shim_1FE50 {
    char p0[8];
    void* prog_info;
    char p0C[0x1C - 0x0C];
    void* prog_mutex;
    void* prog_window;
};

int RGE_Base_Game_check_multi_copies(Shim_1FE50* self)
{
    void* mutex = CreateMutexA(0, 1, (char*)self->prog_info + 4);
    self->prog_mutex = mutex;
    int err = GetLastError();
    if (err != 0xB7) { if (mutex) ReleaseMutex(mutex); return 1; }

    int hw = FindWindowA(0, *(char**)self->prog_info);
    if (hw) {
        if (check_prog_arg(self, "-LOBBY")) {
            SendMessage((void*)hw, 0x10, 0, 0);
            if (mutex) ReleaseMutex(mutex);
            return 1;
        }
        if (IsIconic((void*)hw)) ShowWindow((void*)hw, 1);
        SetForegroundWindow((void*)hw);
        BringWindowToTop(GetLastActivePopup((void*)hw));
    }
    if (mutex) { ReleaseMutex(mutex); CloseHandle(mutex); self->prog_mutex = 0; }
    return 0;
}
