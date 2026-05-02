// VA: 0044D3B0 RGE_Game_Info::save(char* path)
// 181 bytes - size-perfect, 21% diff

int __cdecl rge_open(char* path, int mode, int perm);
int __cdecl rge_close(int fd);
int __cdecl rge_write(int fd, void* buf, int size);

struct TDebuggingLog {
    static void Log(void* L, char* fmt, ...);
};

struct RGE_Person_Info {
    void save(int fd);
};

struct RGE_Game_Info {
    int current_person;
    int people_num;
    RGE_Person_Info** people_info;
    int campaign_num;
    void** campaigns;
    char save_filename[256];

    void save(char* path);
};

extern void* L;
extern int version_marker;

void RGE_Game_Info::save(char* path) {
    TDebuggingLog::Log(L, "(PIF)Creating Player Info File");
    
    // Use strcpy for exact repne scasb + rep movsd match
    char* p = path;
    int i = 0;
    do {
        save_filename[i] = p[i];
        i++;
    } while (p[i-1] != 0);
    
    int fd = rge_open(path, 0x8309, 0x180);
    if (fd == -1) return;
    
    rge_write(fd, &version_marker, 4);
    rge_write(fd, (void*)this, 4);
    rge_write(fd, &people_num, 4);
    
    for (int i = 0; i < people_num; i++) {
        people_info[i]->save(fd);
    }
    
    rge_close(fd);
}
