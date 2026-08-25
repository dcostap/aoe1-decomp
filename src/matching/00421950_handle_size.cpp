// VA: 00421950 RGE_Base_Game::handle_size(void*, unsigned int, unsigned int, long)
// PDB source: basegame.cpp lines 4626-4649 (151 B, 52 asm)
// Attempt log:





extern TPanelSystem panel_system;


int RGE_Base_Game::handle_size(void* p1, unsigned int p2, unsigned int p3, long p4)
{
    if (p3 == 1) return 1;

    if (this->draw_system != 0) {
        this->draw_system->HandleSize(p1, p2, p3, p4);

        if (this->draw_system != 0 && this->draw_system->ScreenWidth != 0) {
            this->prog_info->main_wid = this->draw_system->ScreenWidth;
            this->prog_info->main_hgt = this->draw_system->ScreenHeight;
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->HandleSize(this->prog_info->main_wid, this->prog_info->main_hgt);
        }
    }

    this->endMethod();
    return 1;
}
