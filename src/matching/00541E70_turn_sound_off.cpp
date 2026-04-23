class RGE_Sound {
public:
    void stop(void);
};

class RGE_Game_World {
public:
    char gap_00[0x2C];
    short sound_num;
    char gap_2E[0x2];
    RGE_Sound** sounds;

    void turn_sound_off(void);
};

void RGE_Game_World::turn_sound_off(void) {
    int i = 0;
    if (0 < this->sound_num) {
        do {
            this->sounds[i]->stop();
            ++i;
        } while (i < this->sound_num);
    }
}
