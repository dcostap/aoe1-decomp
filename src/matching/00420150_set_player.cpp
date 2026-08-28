// VA: 00420150 virtual RGE_Base_Game::set_player
// Exact under VC5 host with default /O2 /Oy flags.
// world is at +0x3F4; its player_num, curr_player, and map fields are
// at +0x3C, +0x7C, and +0x28. Keep the null and signed bound guards.




void RGE_Base_Game::set_player(short player_id) {
    RGE_Game_World* w = this->world;
    if (w == 0) return;
    if (player_id >= w->player_num) return;
    w->curr_player = player_id;
    this->world->map->clear_map_view_info();
}
