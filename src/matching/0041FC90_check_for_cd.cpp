// VA: 0041FC90 RGE_Base_Game::check_for_cd (331 B)
// PDB source: basegame.cpp:2977-3028
//
// Attempt log:
// - Replaced the free-function/raw-offset scaffold with the typed
//   RGE_Prog_Info, RGE_Base_Game, TCommunications_Handler, and TRegistry
//   member surfaces.  The source mirrors the original positive-player-count
//   loop and CD-path validation flow.
// - Main-agent audit confirmed canonical member/API ownership and natural CD
//   validation flow; exact bytes were revalidated after promotion.

#include <windows.h>

extern int force_cd;
extern "C" int __cdecl stricmp(const char* left, const char* right);

#ifndef BASEGAME_GROUPED_TU
class RGE_Prog_Info {
public:
    char prog_name[101];
    char prog_version[21];
    char prog_title[121];
    char world_db_file[261];
    char game_data_file[261];
    char vol_name[261];
    char gap_402[0x404 - 0x402];
    unsigned long vol_ser_num;
    int verify_cd;
    int max_players_per_cd;
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(int player);
};

class TRegistry {
public:
    char* RegGetAscii(int use_user, const char* name);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x08];
    RGE_Prog_Info* prog_info;
    char gap_010[0x18C - 0x10];
    TCommunications_Handler* comm_handler;
    char gap_190[0x1AC - 0x190];
    TRegistry* registry;

    int playerHasCD(int player);
    int check_for_cd(int value);
};
#endif

int RGE_Base_Game::check_for_cd(int value)
{
    char vol_name[256];
    char file_sys_name[256];
    unsigned long vol_ser_num;
    unsigned long max_comp_len;
    unsigned long file_sys_flags;

    if (this->prog_info->verify_cd == 0)
        return 1;

    if (value > 0) {
        int cd_count = 0;
        int i = 0;
        do {
            if (this->comm_handler->GetPlayerHumanity(i + 1) == 2 &&
                this->playerHasCD(i) != 0) {
                ++cd_count;
            }
            ++i;
        } while (i < 9);

        return value <= this->prog_info->max_players_per_cd * cd_count;
    }

    if (force_cd != 0)
        return 1;

    char* path = this->registry->RegGetAscii(0, "CDPath");
    if (path == 0)
        return 0;

    if (GetDriveTypeA(path) != 5)
        return 0;

    if (GetVolumeInformationA(path, vol_name, 256, &vol_ser_num,
                               &max_comp_len, &file_sys_flags,
                               file_sys_name, 256) == 0)
        return 0;

    return stricmp(vol_name, this->prog_info->vol_name) == 0;
}
