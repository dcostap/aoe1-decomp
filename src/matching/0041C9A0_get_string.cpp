static char g_string_buffer[0x200];

char* RGE_Base_Game::get_string(long id)
{
    this->get_string(id, g_string_buffer, 0x200);
    return g_string_buffer;
}
