class RGE_Sound {
public:
    short field_0;
    void play_at_update();
};

void RGE_Sound::play_at_update() { this->field_0++; }
