// 00543E00 RGE_Game_World::load_scenario (World.cpp:2309-2388)
// Shared World.cpp context reconstruction. Accepted drift remains 657 bytes
// versus 642, with 147 differing bytes and 24 ordered calls. The late close
// block stays structurally different from the oracle.
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::load_scenario(char* name, RGE_Player_Info* info)
{
    char scenario_name[304];
    int version;
    int header_size;
    int file;
    void* buf;
    world_update_counter = 0;
    sprintf(scenario_name + 4, "%s%s", rge_base_game->prog_info->scenario_dir, name);
    if (name != 0) {
        file = rge_open(scenario_name + 4, 0x8000);
        if (file != -1) {
            rge_read_uncompressed(file, scenario_name, 4);
            if (*(int*)scenario_name == version_101) {
                this->load_scenario1(file, *info);
                this->setup_player_colors(info);
                return 1;
            }
            if (*(int*)scenario_name == version_102) {
                goto version2;
            }
            if (*(int*)scenario_name == version_103) {
                rge_read_uncompressed(file, &version, 4);
                if (version <= 0) {
                    goto version2;
                }
                buf = malloc(version);
                if (buf != 0) {
                    rge_read_uncompressed(file, buf, version);
                    free(buf);
                    goto version2;
                }
            } else {
                if (*(int*)scenario_name == version_104) {
                    this->load_scenario3(file, *info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_105) {
                    this->load_scenario4(file, *info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_106) {
                    this->load_scenario5(file, *info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_107) {
                    this->load_scenario6(file, *info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_108) {
                    this->load_scenario7(file, *info);
                    this->setup_player_colors(info);
                    return 1;
                }
                if (*(int*)scenario_name == version_109 ||
                    *(int*)scenario_name == version_111) {
                    goto version110;
                }
                if (*(int*)scenario_name != version_110) {
                    goto close_failed;
                }
version110:
                this->load_scenario8(file, *info);
                this->setup_player_colors(info);
                return 1;
            }
close_failed:
            rge_close(file);
        }
    }
    return 0;

version2:
    this->load_scenario2(file, *info);
    this->setup_player_colors(info);
    return 1;
}
