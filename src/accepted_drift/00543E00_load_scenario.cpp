// 00543E00 RGE_Game_World::load_scenario (World.cpp:2309-2388)
// Shared World.cpp context reconstruction. The current 657-byte source has
// 77 differing bytes and all 24 call targets. Only the late close/success call
// order and the duplicated zero-result epilogue remain different.
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::load_scenario(char* name, RGE_Player_Info& info)
{
    char scenario_name[300];
    int header_size;
    int version;
    int file;
    world_update_counter = 0;
    sprintf(scenario_name, "%s%s", rge_base_game->save_prog_info->scenario_dir, name);
    if (name != 0) {
        file = rge_open(scenario_name, 0x8000);
        if (file != -1) {
            rge_read_uncompressed(file, &header_size, 4);
            if (header_size == version_101) {
                this->load_scenario1(file, info);
                goto success;
            }
            if (header_size == version_102) {
                goto version2;
            }
            if (header_size == version_103) {
                rge_read_uncompressed(file, &version, 4);
                if (version <= 0) {
                    goto version2;
                }
                void* buf = malloc(version);
                if (buf == 0) {
                    goto close_failed;
                }
                rge_read_uncompressed(file, buf, version);
                free(buf);
                goto version2;
            }
            if (header_size == version_104) {
                this->load_scenario3(file, info);
                goto success;
            }
            if (header_size == version_105) {
                this->load_scenario4(file, info);
                goto success;
            }
            if (header_size == version_106) {
                this->load_scenario5(file, info);
                goto success;
            }
            if (header_size == version_107) {
                this->load_scenario6(file, info);
                goto success;
            }
            if (header_size == version_108) {
                this->load_scenario7(file, info);
                goto success;
            }
            if (header_size != version_109 &&
                header_size != version_111 &&
                header_size != version_110) {
                goto close_failed;
            }
            this->load_scenario8(file, info);
success:
            this->setup_player_colors(info);
            return 1;
close_failed:
            rge_close(file);
        }
    }
    return 0;

version2:
    this->load_scenario2(file, info);
    goto success;
}

// BINARY NOTE: The target reads the scenario directory through the +0x0c
// RGE_Base_Game pointer. Exact World.cpp donors use save_prog_info for this
// field. The prog_info field in the full class is at +0x10.
//
// BINARY NOTE: The PDB symbol uses a protected RGE_Player_Info reference.
// The frame has a 300-byte path, a separate header word, and one version word.
// One shared success statement recovers the target register map and all eight
// setup calls. This reduced strict drift from 147 bytes to 77 bytes.
//
// BINARY NOTE: The full World.cpp /GX wrapper emits the same 657-byte body.
// Its six configured exact anchors remain exact. Natural late-guard forms and
// VC5 debug flags keep the same close-before-version-8 block. The remaining
// output has ten returns; the oracle shares one zero-result epilogue and has nine.
