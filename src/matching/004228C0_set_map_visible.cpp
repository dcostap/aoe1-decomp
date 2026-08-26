void RGE_Base_Game::set_map_visible(unsigned char param)
{
    if (this->world)
        this->world->set_map_visible((unsigned char)param);
}
