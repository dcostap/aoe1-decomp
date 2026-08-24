// VA: 0053D720 RGE_Diamond_Map_View::mouse_right_up_action(long,long,int,int)
// PDB source: vw_dimap.cpp lines 206-261
// The shared vw_dimap context supplies the reviewed class and ABI surface.

long RGE_Diamond_Map_View::mouse_right_up_action(long x, long y, int param_3, int param_4)
{
    RGE_Tile* tile;
    int mode = rge_base_game->prog_mode;
    if (mode != 4 && mode != 6 && mode != 7 && mode != 5) {
        return 0;
    }

    if (this->scrolling != 0) {
        this->end_scroll_view();
        return 1;
    }

    this->release_mouse();
    if (rge_base_game->get_paused() != 0) {
        return 0;
    }

    if (this->field_EC != 1 && this->field_EC != 2) {
        return 0;
    }

    if (rge_base_game->prog_info->interface_style == 2) {
        if (rge_base_game->game_mode != 0 || rge_base_game->prog_mode == 5) {
            return 0;
        }
        if (param_4 == 0) {
            if (this->right_click2(x, y) == 0) {
                goto fail;
            }
            return 1;
        }
        if (this->pick_tile(x, y, (short*)&x, (short*)&y, &tile) != 0) {
            this->player->set_view_loc((float)(short)x - -0.5f, (float)(short)y - -0.5f, 1.0f);
        }
        return 1;
    }

    if (rge_base_game->prog_mode == 7) {
        return 0;
    }
    if (rge_base_game->game_mode != 0) {
        rge_base_game->set_game_mode(0, 0);
        return 0;
    }
    this->player->unselect_object();
fail:
    return 0;
}
