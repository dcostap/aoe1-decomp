// VA: 0041EBC0 RGE_Base_Game::setup_palette (41 B)
// PDB source: basegame.cpp, lines 2383-2398



extern TPanelSystem panel_system;
int RGE_Base_Game::setup_palette()
{
    void* result = panel_system.get_palette(this->prog_info->pal_file, 0xC544);
    this->prog_palette = result;
    return result != 0;
}
