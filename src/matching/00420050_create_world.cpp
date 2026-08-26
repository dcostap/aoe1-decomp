// tried the natural `return new RGE_Game_World;` shape first; default flags only built a 32-byte body
// /GX was required to land the EH/new helper in the exact 90-byte basin
RGE_Game_World* RGE_Base_Game::create_world() {
    return new RGE_Game_World;
}
