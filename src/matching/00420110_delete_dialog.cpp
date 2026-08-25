


void RGE_Base_Game::delete_dialog(VBase** p)
{
    if (*p) {
        (*p)->scalar_deleting_destructor(1);
        *p = 0;
    }
}
