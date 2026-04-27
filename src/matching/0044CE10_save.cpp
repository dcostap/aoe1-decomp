// VA: 0044CE10 RGE_Person_Info::save(int fd)
// gameinfo.cpp lines 329-340, 120 bytes

void __cdecl rge_write(int fd, void* buf, int size);

struct TDebuggingLog {
    static void Log(void* L, char* fmt, ...);
};

struct RGE_Campaign_Info {
    void save(int fd);
};

struct RGE_Person_Info {
    char name[256];               // +0x00
    int current_campaign;         // +0x100
    int campaign_info_num;        // +0x104
    RGE_Campaign_Info** campaign_info; // +0x108

    void save(int fd);
};

extern int L;

void RGE_Person_Info::save(int fd) {
    TDebuggingLog::Log((void*)L, "(PIF)Saving player - %s", this);
    rge_write(fd, this, 0xFF);
    rge_write(fd, &current_campaign, 4);
    rge_write(fd, &campaign_info_num, 4);
    for (int i = 0; i < campaign_info_num; i++) {
        campaign_info[i]->save(fd);
    }
}
