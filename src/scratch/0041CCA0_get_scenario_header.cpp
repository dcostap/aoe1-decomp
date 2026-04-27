// VA: 0041CCA0 RGE_Base_Game::get_scenario_header (253 B)
// PDB source: basegame.cpp
// Packet-grounded: sprintf path, rge_open/open_scenario, read 4-byte version, compare against known versions, virtual dispatch

extern int sprintf(char* buf, const char* fmt, ...);
extern int rge_open(const char* path, int flags);
extern int rge_read_uncompressed(int fd, void* buf, int len);
extern int rge_close(int fd);
extern int RGE_Game_Info_open_scenario(void* info);

struct Shim_1CCA0 {
    void* vtable;              // +0x00
    char p4[4];
    void* player_game_info;    // +0x04
    char p8[0x0C - 0x08];
    void* prog_info;           // +0x0C
};

void* RGE_Base_Game_get_scenario_header(Shim_1CCA0* self, char* param1, int param2)
{
    char temp_name[300];
    int fd;
    int version;
    void* result;
    
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
    
    rge_read_uncompressed(fd, temp_name, 4);
    version = *(int*)temp_name;
    
    result = 0;
    if (version == *(int*)"1.03" ||
        version == *(int*)"1.04" ||
        version == *(int*)"1.05" ||
        version == *(int*)"1.06" ||
        version == *(int*)"1.07" ||
        version == *(int*)"1.08" ||
        version == *(int*)"1.09" ||
        version == *(int*)"1.10" ||
        version == *(int*)"1.11")
    {
        result = (void*)((int(*)(int))(*(int**)self)[0x38/4])(fd);
    }
    
    rge_close(fd);
    return result;
}
