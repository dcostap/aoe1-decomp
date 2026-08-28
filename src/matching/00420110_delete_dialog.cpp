


void RGE_Base_Game::delete_dialog(TPanel** p)
{
    if (*p) {
        delete *p;
        *p = 0;
    }
}
