class RGE_Sound {
public:
    void stop(void);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    short sound_num;
    RGE_Sound** sounds;

    virtual void pause(unsigned char paused);
};

void RGE_Game_World::pause(unsigned char paused) {
    int i;

    if (paused != 0) {
        i = 0;
        if (this->sound_num > 0) {
            do {
                this->sounds[i]->stop();
                i = i + 1;
            } while (i < this->sound_num);
        }
    }
}
