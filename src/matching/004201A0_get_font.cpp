

void* RGE_Base_Game::get_font(int index)
{
    if (!this->font_ptr)
        return 0;
    return (char*)this->font_ptr + index * 12;
}
