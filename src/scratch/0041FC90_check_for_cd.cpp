// VA: 0041FC90 RGE_Base_Game::check_for_cd (331 B)
// PDB source: basegame.cpp
// Packet-grounded: verify_cd check, count players with CD, or reg lookup + volume match

extern int GetPlayerHumanity(int handler, int idx);
extern int playerHasCD(void* self, int idx);
extern int GetDriveTypeA(const char* path);
extern int GetVolumeInformationA(const char* root, char* vol_name, int vol_len, int* ser_num, int* max_comp, int* flags, char* fs_name, int fs_len);
extern int stricmp(const char* a, const char* b);
extern char* RegGetAscii(void* registry, int def, const char* key);
extern int force_cd;

struct Shim_1FC90 {
    char p0[0x0C];
    void* prog_info;           // +0x0C
    char p10[0x18C - 0x10];
    int comm_handler;          // +0x18C
    char p190[0x1AC - 0x190];
    void* registry;            // +0x1AC
};

int RGE_Base_Game_check_for_cd(Shim_1FC90* self, int param)
{
    int i;
    int count;
    int cd_count;
    char vol_name[256];
    char fs_name[256];
    int ser_num, max_comp, flags;
    char* path;
    int drive_type;
    
    if (*(int*)((char*)self->prog_info + 0x408) == 0)
        return 1;
    
    if (param > 0) {
        count = 0;
        for (i = 0; i < 9; i++) {
            if (GetPlayerHumanity(self->comm_handler, i + 1) == 2) {
                if (playerHasCD(self, i))
                    count++;
            }
        }
        cd_count = *(int*)((char*)self->prog_info + 0x40C);
        return (param <= cd_count * count) ? 1 : 0;
    }
    
    if (force_cd)
        return 1;
    
    path = RegGetAscii(self->registry, 0, "CDPath");
    if (!path)
        return 0;
    
    drive_type = GetDriveTypeA(path);
    if (drive_type != 5)
        return 0;
    
    if (!GetVolumeInformationA(path, vol_name, 256, &ser_num, &max_comp, &flags, fs_name, 256))
        return 0;
    
    return (stricmp(vol_name, (char*)self->prog_info + 0x2FD) == 0) ? 1 : 0;
}
