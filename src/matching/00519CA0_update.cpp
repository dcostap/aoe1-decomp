// VA: 00519CA0 TRIBE_Gaia::update()
// PDB source: tplayer.cpp lines 5297-5309
// Match: 102/102 bytes, 0.0000%
// Key: explicit assignment (= a + b not +=), 1.0f literal (not const float variable)

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Game_World {
public:
    char pad_00[0x84];
    float update_period;
};

class RGE_Player {
public:
    char pad_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x808];
    float update_time;
    long update_nature;

    void update();
};

class TRIBE_Gaia : public RGE_Player {
public:
    void update();
};
#endif

void TRIBE_Gaia::update() {
    this->update_time = this->update_time + this->world->update_period;
    if (this->update_time > 1.0f) {
        do {
            this->update_time = this->update_time - 1.0f;
            if (++this->update_nature == 0x1E) {
                this->update_nature = 0;
            }
        } while (this->update_time > 1.0f);
    }
    RGE_Player::update();
}
