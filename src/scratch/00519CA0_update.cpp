// attempt log:
// first pass: natural while-loop on the gaia update timer with the inherited world pointer and tail-call to base update
// second pass: switch to explicit local stubs for RGE_Player and the global period so the base-call/offset layout can compile cleanly
// paused here: the arithmetic is right, but VC5 keeps shifting the FPU compare/basin when the period is spelled directly
// target shape: add world->period at +0x84 into update_time, wrap at the global period, increment update_nature and wrap at 0x1E, then tail-call base update

#define GAIA_PERIOD (*(float*)0x576824)

class RGE_Game_World {
public:
    char gap_00[0x84];
    float update_period;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x220 - 0x40];
    void update(void);
};

class TRIBE_Gaia : public RGE_Player {
public:
    char gap_220[0x848 - 0x220];
    float update_time;
    long update_nature;
    long last_count;
    long animal_max;

    void update(void);
};

void TRIBE_Gaia::update(void) {
    float delta = this->world->update_period;
    this->update_time += delta;
    while (this->update_time >= GAIA_PERIOD) {
        this->update_time -= GAIA_PERIOD;
        ++this->update_nature;
        if (this->update_nature == 0x1E) {
            this->update_nature = 0;
        }
    }
    RGE_Player::update();
}
