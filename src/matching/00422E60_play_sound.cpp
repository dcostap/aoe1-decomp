class TDigital {
public:
    int is_playing(void);
    int play(void);
};

class RGE_Base_Game {
public:
    char gap_00[0x6C];
    TDigital** sounds;

    int play_sound(int param_1);
};

int RGE_Base_Game::play_sound(int param_1)
{
    if (this->sounds == 0)
        return 0;

    if (this->sounds[param_1] == 0)
        return 0;

    if (this->sounds[param_1]->is_playing() != 0)
        return 1;

    return this->sounds[param_1]->play();
}
