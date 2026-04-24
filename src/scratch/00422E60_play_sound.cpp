// tried direct wrapper shapes with/without a local sound temp; VC5 kept flipping the post-is_playing branch polarity
// tried an explicit if-not/play form and a one-temp form; the remaining mismatch stayed at the is_playing -> play transition
// leaving in scratch because the call target and null checks are right, but the branch shape still lands in the wrong basin
class TDigital {
public:
    int is_playing();
    int play();
};

class RGE_Base_Game {
public:
    char gap_00[0x6C];
    TDigital** sounds;

    int play_sound(int param_1);
};

int RGE_Base_Game::play_sound(int param_1)
{
    TDigital* sound;

    if (this->sounds == 0)
        return 0;

    sound = this->sounds[param_1];
    if (sound == 0)
        return 0;

    if (sound->is_playing() == 0)
        sound->play();

    return 1;
}
