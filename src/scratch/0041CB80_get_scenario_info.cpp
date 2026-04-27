// VA: 0041CB80 RGE_Base_Game::get_scenario_info (275 B)
// PDB source: basegame.cpp
// Packet-grounded: sprintf path, rge_open, read obj_id/version, malloc+read+free, rge_read type, virtual dispatch

extern int sprintf(char* buf, const char* fmt, ...);
extern int rge_open(const char* path, int flags);
extern int rge_read_uncompressed(int fd, void* buf, int len);
extern int rge_read(int fd, void* buf, int len);
extern int rge_close(int fd);
extern int RGE_Game_Info_open_scenario(void* info);
extern void* malloc(int size);
extern int free(void* p);

struct Shim_1CB80 {
    void* vtable;              // +0x00
    char p4[4];
    void* player_game_info;    // +0x04
    char p8[0x0C - 0x08];
    void* prog_info;           // +0x0C
};

void* RGE_Base_Game_get_scenario_info(Shim_1CB80* self, char* param1, int param2)
{
    char temp_name[300];
    int fd;
    int version;
    int obj_id;
    int header_type;
    void* result;
    void* buf;
    
    sprintf(temp_name + 4, "%s%s", (char*)self->prog_info + 0xC17, param1);
    
    if (param2) {
        fd = RGE_Game_Info_open_scenario(self->player_game_info);
    } else {
        if (!param1)
            return 0;
        fd = rge_open(temp_name + 4, 0x8000);
    }
    
    if (fd == -1)
        return 0;
    
    rge_read_uncompressed(fd, &obj_id, 4);
    rge_read_uncompressed(fd, &version, 4);
    
    if (version > 0) {
        buf = malloc(version);
        if (!buf) {
            rge_close(fd);
            return 0;
        }
        rge_read_uncompressed(fd, buf, version);
        free(buf);
    }
    
    rge_read(fd, &header_type, 4);
    
    result = (void*)((int(*)(int))(*(int**)self)[0x3C/4])(fd);
    rge_close(fd);
    return result;
}
