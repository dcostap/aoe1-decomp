

RGE_Font* RGE_Base_Game::get_font(int index)
{
    if (!this->fonts)
        return 0;
    return this->fonts + index;
}
