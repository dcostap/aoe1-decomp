// 00544090 RGE_Game_World::load_scenario (World.cpp:2393-2465)
// Shared World.cpp context reconstruction. Accepted drift remains 443 bytes
// versus 440, with 197 differing bytes and 17 ordered calls. The remaining
// difference is the cold failure-tail branch layout.
#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::load_scenario(RGE_Player_Info& info) {
    int header_size;
    int version;
    int file;

    world_update_counter = 0;
    file = rge_base_game->campaign_open_scenario();
    if (file == -1) {
        goto cleanup;
    }

    rge_read_uncompressed(file, &header_size, 4);

    if (header_size == version_101) {
        this->load_scenario1(file, info);
        goto success;
    }

    if (header_size == version_102) {
        goto shared_80;
    }

    if (header_size == version_103) {
        rge_read_uncompressed(file, &version, 4);
        if (version > 0) {
            void* buffer = malloc(version);
            if (buffer == 0) {
                goto fail;
            }
            rge_read_uncompressed(file, buffer, version);
            free(buffer);
        }
        goto shared_80;
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
    if (header_size == version_109 ||
        header_size == version_111 ||
        header_size == version_110) {
        this->load_scenario8(file, info);
        goto success;
    } else {
        goto fail;
    }

shared_80:
    this->load_scenario2(file, info);
    goto success;

success:
    this->setup_player_colors(&info);
    rge_base_game->get_campaign_info(&this->campaign,
                                     &this->campaign_player,
                                     &this->campaign_scenario);
    return 1;

fail:
    rge_close(file);
cleanup:
    return 0;
}
