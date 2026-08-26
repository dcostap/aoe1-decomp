


void RGE_Base_Game::delete_dialog(TPanel** p)
{
    if (*p) {
        ((VBase*)*p)->scalar_deleting_destructor(1);
        *p = 0;
    }
}
