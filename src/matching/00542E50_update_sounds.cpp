class RGE_Sound {
public:
    void update(unsigned long value);
};

class RGE_Game_World {
public:
    char gap_00[0x20];
    int sound_update_index;
    char gap_24[0x08];
    short sound_num;
    char gap_2E[0x02];
    RGE_Sound** sounds;

    void update_sounds(unsigned long value);
};

void RGE_Game_World::update_sounds(unsigned long value) {
    if (this->sound_update_index >= (int)this->sound_num) {
        this->sound_update_index = 0;
    }
    this->sounds[this->sound_update_index]->update(value);
    this->sound_update_index = this->sound_update_index + 1;
}
