void RGE_Base_Game::set_map_fog(int param)
{
    if (this->world)
        this->world->set_map_fog((unsigned char)param);
}
