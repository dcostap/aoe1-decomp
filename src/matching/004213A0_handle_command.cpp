

int RGE_Base_Game::handle_command(void* a, unsigned int b, unsigned int c, long d)
{
    return this->action_command((unsigned long)c, (unsigned long)d) != 0;
}
