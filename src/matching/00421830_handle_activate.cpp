// VA: 00421830 RGE_Base_Game::handle_activate (215 B)
// PDB source: basegame.cpp lines 4537-4598
// Attempt log:
// baseline reconstruction: named RGE_Base_Game fields, natural active/inactive
// branches, typed direct helpers, and virtual dispatch surfaces from the packet.
// The complete panel and base-game call surface produced the exact match.





extern TPanelSystem panel_system;


int RGE_Base_Game::handle_activate(void* param_1, unsigned int param_2,
                                   unsigned int param_3, long param_4)
{
    if (param_3 != 0) {
        this->prog_active = 1;
    } else {
        this->prog_active = 0;
    }

    if (this->prog_active != 0) {
        if ((this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) &&
            this->auto_paused == 1) {
            this->auto_paused = 0;
            this->set_paused(0, 0);
        }

        TPanel* panel = panel_system.currentPanel();
        if (panel != 0) {
            panel = panel_system.currentPanel();
            panel->handle_reactivate();
        }
        this->action_activate();
    } else {
        if (this->prog_mode == 4 || this->prog_mode == 6 || this->prog_mode == 7) {
            if (this->singlePlayerGame() == 1 && this->get_paused() == 0) {
                this->auto_paused = 1;
                this->set_paused(1, 0);
            }
        }
        this->action_deactivate();
    }

    return 1;
}
