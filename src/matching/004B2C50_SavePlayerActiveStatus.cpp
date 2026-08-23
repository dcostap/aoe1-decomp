// VA: 004B2C50 TRIBE_Screen_Sed::SavePlayerActiveStatus (383 B)
// PDB source: scr_sed2.cpp:2258-2290
// Baseline: typed period-style panel/world/scenario reconstruction from the
// proven fields and direct-call surface.
// Attempt log:
// - The typed baseline matched size/frame/calls and left only the final
//   player-count comparison operand order different (2 bytes).
// - Spelled the final guard as `this->player_num >= active_players`, matching
//   the original `cmp player_num,active_players; jl` and producing an exact
//   match.

#include "../../include/scr_sed2_context.h"

void TRIBE_Screen_Sed::SavePlayerActiveStatus()
{
    int active_players = this->player_number_list->get_line() + 1;
    int i = 0;

    for (; i < this->world->player_num - 1; ++i) {
        this->world->scenario->Set_player_Active(i, i < active_players);
    }

    this->victory_player_list->empty_list();
    this->victory_enemy_player_list->empty_list();
    this->options_player_list->empty_list();
    this->Diplomacy_player_list->empty_list();
    this->player_list->empty_list();
    this->unit_player_list->empty_list();

    this->unit_player_list->append_line(0x2776, 0);

    if (active_players > 0) {
        int string_id = 0x2865;
        do {
            this->unit_player_list->append_line(string_id, 0);
            this->victory_player_list->append_line(string_id, 0);
            this->victory_enemy_player_list->append_line(string_id, 0);
            this->options_player_list->append_line(string_id, 0);
            this->Diplomacy_player_list->append_line(string_id, 0);
            this->player_list->append_line(string_id, 0);
            ++string_id;
        } while (string_id - 0x2865 < active_players);
    }

    if (this->player_num >= active_players) {
        this->set_player((short)active_players, 0, 0);
    }

    this->victory_player_list->set_line((long)this->player_num - 1);
    this->options_player_list->set_line((long)this->player_num - 1);
    this->Diplomacy_player_list->set_line((long)this->player_num - 1);
    this->player_list->set_line((long)this->player_num - 1);
    this->unit_player_list->set_line((long)this->player_num);
}
