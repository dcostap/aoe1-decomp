// Variant lab for 00519C40_save (TRIBE_Gaia::save, tplayer.cpp, 91 bytes)

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class TRIBE_Player {
public:
    virtual void save(int);
};

void rge_write(int, void*, int);

class TRIBE_Gaia : public TRIBE_Player {
public:
    char gap_00[0x844];
    int update_time;
    int update_nature;
    int last_count;
    int animal_max;

    void save(int param_1);
};
#endif

void TRIBE_Gaia::save(int param_1) {
    TRIBE_Player::save(param_1);

    rge_write(param_1, &this->update_time, 4);
    rge_write(param_1, &this->update_nature, 4);
    rge_write(param_1, &this->animal_max, 4);
    rge_write(param_1, &this->last_count, 4);
}
