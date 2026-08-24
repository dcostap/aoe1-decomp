// VA: 0044C8A0 RGE_Campaign_Info::save(int fd)
// gameinfo.cpp lines 142-152, 138 bytes

#ifndef GAMEINFO_SHARED_CONTEXT
void __cdecl rge_write(int fd, void* buf, int size);

struct TDebuggingLog {
    static void Log(void* L, char* fmt, ...);
};

struct RGE_Campaign;

struct RGE_Campaign_Info {
    char name[256];           // +0x00
    int current_scenario;     // +0x100
    int scenario_num;         // +0x104
    char* scenario_info;      // +0x108
    int last_scenario;        // +0x10C
    RGE_Campaign* campaign;   // +0x110

    void save(int fd);
};

extern int L;
#endif

void RGE_Campaign_Info::save(int fd) {
    TDebuggingLog::Log((void*)L, "  (PIF)Saving campaign - (%d) %s", last_scenario, this);
    rge_write(fd, this, 0xFF);
    rge_write(fd, &current_scenario, 4);
    rge_write(fd, &scenario_num, 4);
    rge_write(fd, &last_scenario, 4);
    if (scenario_num > 0) {
        rge_write(fd, scenario_info, scenario_num);
    }
}
