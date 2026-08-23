// VA: 004AD340 TRIBE_Screen_Sed::command_new_map | scr_sed.cpp:3308-3408
// Attempt log:
// baseline: natural status/world/map-generation reconstruction with named local
// records and the bounded active-player scan.
// probe: while-loop scan removed VC5's peeled duplicate get_player_active call;
// it matched the ten-call multiset and original effective size, but not CFG.
// probe: canonical RGE_Player_Info plus a separate name-base local recovered the
// proven name/type/color/hash and scenario/map-info stack ownership; the local
// map payload uses its binary-proven land anchor at offset zero.
// probes: captured-this alias, declaration-order swaps, result lifetime, and
// TScreenPanel base context were codegen-neutral; field-home padding was neutral.
// probe: delaying the receiver alias until after the status gate, following the
// direct-this shape in same-TU command donors, was codegen-neutral.
// probe: an explicit unsigned-byte cast on the typed new-map dispatch preserved
// the source model but emitted the same code; rolled back.
// probe: direct scenario-status branch calls tail-merge to the original single
// call site with branch-specific 44e/44f pushes; retained as the best source.
// blocker: original begins `mov eax,ecx`, homes this at [esp+10h], and keeps
// show_status in ESI; VC5 retains this in ESI, zeroes EBX early, and emits a
// 570-byte/576-compared basin despite matching frame/saved-register set/calls.
// probe: a typed initial-world snapshot produced the original early load/test
// shape, but worsened the basin to 576 bytes and diff 559; it was rolled back.
// probe: modeling the map land header as short clump_num changed the byte store
// to the original word store and improved diff 505 to 503.
// probe: initializing player_num before the scan and writing hash[8] after it
// recovered the original stack order and improved diff 503 to 465; retained.
// probe: splitting new_scenario result assignment from byte narrowing produced
// the target EAX mask and improved diff 465 to 433; the one-statement uchar ABI
// form emits the same best bytes and is retained.
// probes: receiver pointer/reference aliases and a scoped game pointer were
// codegen duplicates or worsened structure; retained the simplest pointer form.
// blocker: target still homes receiver/current-tribe locals in opposite slots
// and differs in early register/global-load coloring despite matching calls,
// frame, size, and CFG signals.
// revisit: restore the reviewed TRIBE_Game global surface and remove the
// accessor/game aliases. The original homes this at [esp+10] and reloads the
// global for each game operation; a persistent game alias adds the wrong home.
// revisit result: direct global access restored the 0x7D8 frame, 159 emitted
// instructions, and the 10-call set; strict diff improved 489 to 433 bytes.
// revisit probes: a scoped game pointer worsened the result to 544 bytes;
// receiver pointer/reference aliases, declaration moves, canonical screen
// fields, and the RGE_Base_Game base surface were neutral or codegen-duplicate.
// probe: split world->player_num at +0x3C from world->player_count at +0x44;
// the loop reads +0x44 while the post-new-scenario limit reads +0x3C. This
// improved structural shape from 85.53% to 86.16% without changing size.
// final lead: keep the typed TRIBE_Game/RGE_Game_World scenario-editor flow;
// the remaining gap is the original register/home coloring and one-byte size.
// continuation: declare the loop index at its first loop. This restores the
// 590-byte boundary and improves the strict difference from 433 to 330 bytes.
// Earlier function-scope index lifetime made VC5 add one byte at the boundary.
// continuation: authentic nearby owners from 004AAE20 through 004ADC40 were
// added in PDB order. They preserve this 590-byte basin but do not change its
// early this/current-tribe home swap. Alias, reference, initial-world, game,
// increment, initializer-order, and scalar-scope variants did not fix it.
// exact finish: the PDB lists only player_info, tribe, and map_info as stack
// locals. Removing the synthetic name-base local and passing 0x2865 + i lets
// VC5 create its own compensated induction spill. This also gives the compiler
// temp the first low frame home and places tribe in its PDB-proved -0x7D4 home.
// exact reduction: `i + 0x2865`, an explicit long cast, and the old scalar name
// are byte-identical. Unused or dead name-base locals are also incidental.
// Reconnecting that synthetic local returns the old 330-byte mismatch when the
// incidental comment-line state is absent, so the direct constant stays.
// FLAGS: default config/flags/default.rsp (/nologo /c /O2 /Oy).

#include "../../include/scr_sed_context.h"

int TRIBE_Screen_Sed::command_new_map(char* scenario_name_in, int is_multi_player_in,
                                      int random_seed_in, int width, int height,
                                      int display_in)
{
    int tribe;
    int result;
    RGE_Player_Info player_info;
    RGE_Map_Gen_Info map_info;

    this->need_to_save_flag = 0;
    if (rge_base_game->world == 0) {
        if (display_in != 0) {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44d, 0, -1);
        }
        if (((TRIBE_Game*)rge_base_game)->load_game_data() == 0) {
            if (display_in != 0) {
                ((TRIBE_Game*)rge_base_game)->close_status_message();
            }
            return 0;
        }
    }

    this->world = rge_base_game->world;
    if (display_in != 0) {
        if (scenario_name_in == 0) {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44e, 0, -1);
        } else {
            ((TRIBE_Game*)rge_base_game)->show_status_message(0x44f, 0, -1);
        }
    }

    player_info.scenario = scenario_name_in;
    player_info.map_info = (RGE_Map_Gen_Info*)&map_info.land;
    player_info.map_width = (short)width;
    player_info.map_height = (short)height;
    player_info.ai_info = 0;
    player_info.player_num = 8;
    tribe = 0;

    int i;
    for (i = 0; i < 8; i++) {
        tribe++;
        if (tribe >= this->world->player_count) {
            tribe = 1;
        }
        this->set_string(player_info.name[i], 0x2865 + i, 0x41);
        player_info.type[i] = 0;
        player_info.tribe[i] = (char)tribe;
        player_info.color[i] = -1;
        player_info.player_id_hash[i] = i;
    }
    player_info.player_id_hash[i] = i;
    map_info.land.clump_num = 0;

    if (rge_base_game->sound_system != 0) {
        ((Sound_Driver*)rge_base_game->sound_system)->mute = 1;
    }
    result = this->world->new_scenario(&player_info, random_seed_in) & 0xff;
    if (result != 0 && this->world->player_num < 8) {
        result = 0;
        this->world->del_game_info();
    }
    if (rge_base_game->sound_system != 0) {
        ((Sound_Driver*)rge_base_game->sound_system)->mute = 0;
    }

    if (result != 0 && this->player_number_list != 0) {
        i = 0;
        while (i < 8) {
            if (this->world->scenario->Get_player_Active(i) == 0) {
                break;
            }
            i++;
        }
        if (i < 8 && i > 0) {
            this->player_number_list->set_line(i - 1);
        }
        this->SavePlayerActiveStatus();
    }
    return result;
}
