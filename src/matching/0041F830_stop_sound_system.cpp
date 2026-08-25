// VA: 0041F830 RGE_Base_Game::stop_sound_system
void operator delete(void* p);
extern "C" void __cdecl free(void* block);

void RGE_Base_Game::stop_sound_system(void) {
    if (chat != 0)
        chat->StopSoundSystem();

    panel_system.stop_sound_system();

    if (this->world != 0) {
        for (int i = 0; i < this->world->sound_num; ++i)
            this->world->sounds[i]->restart_sound(0);
    }

    if (this->sounds != 0) {
        for (int i = 0; i < this->sound_num; ++i) {
            if (this->sounds[i] != 0)
                delete this->sounds[i];
        }
        free(this->sounds);
        this->sounds = 0;
    }

    this->shutdown_music_system();

    if (this->sound_system != 0) {
        this->registry->RegSetInt(1, "Sound Volume", -this->sound_system->get_volume());
        delete this->sound_system;
        this->sound_system = 0;
        sound_driver = 0;
    }
}
