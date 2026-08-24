void rge_write(int file, void* data, int size);
#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Player { public: virtual void scenario_save(int file); };
class TRIBE_Player : public RGE_Player { public: char pad_04[0x50-4]; char* field_50; virtual void scenario_save(int file); };
#endif
void TRIBE_Player::scenario_save(int file) {
    RGE_Player::scenario_save(file);
    rge_write(file, this->field_50, 4);
    rge_write(file, this->field_50 + 4, 4);
    rge_write(file, this->field_50 + 12, 4);
    rge_write(file, this->field_50 + 8, 4);
}
