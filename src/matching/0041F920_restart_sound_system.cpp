// VA: 0041F920 RGE_Base_Game::restart_sound_system
int RGE_Base_Game::restart_sound_system()
{
    if (this->sound_system != 0)
        goto done;

    if (this->setup_sound_system() == 0)
        return 0;
    if (this->setup_sounds() == 0)
        return 0;

    if (this->world != 0) {
        for (int i = 0; i < this->world->sound_num; ++i)
            this->world->sounds[i]->restart_sound(this->sound_system);
    }

    panel_system.restart_sound_system();

    if (chat != 0)
        chat->RestartSoundSystem(this->sound_system);

    this->restart_music_system();

done:
    return 1;
}
