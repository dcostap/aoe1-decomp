// VA: 00540CF0 RGE_Game_World::reset_object_count (51 B)
// PDB source: World.cpp lines 348-362

class RGE_Game_World {
public:
    void* vtable_ptr;                  // +0x00
    unsigned long world_time;          // +0x04
    unsigned long old_world_time;      // +0x08
    unsigned long world_time_delta;    // +0x0C
    float timer;                       // +0x10
    unsigned long old_time;            // +0x14
    float game_speed;                  // +0x18
    char temp_pause;                   // +0x1C
    char gap_1D[0x68 - 0x1D];          // +0x1D..+0x67
    unsigned long next_object_id;      // +0x68
    char gap_6C[0x84 - 0x6C];          // +0x6C..+0x83
    float world_time_delta_seconds;    // +0x84
    char gap_88[0xB0 - 0x88];          // +0x88..+0xAF
    unsigned long player_turn;         // +0xB0
    unsigned long player_time_delta[9];// +0xB4

    void reset_object_count();
};

void RGE_Game_World::reset_object_count() {
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->world_time_delta_seconds = 0.0f;
    this->timer = 0.0f;
    this->old_time = 0;
    this->temp_pause = 0;
    this->next_object_id = 0;
    this->player_turn = 0;

    for (int i = 0; i < 9; ++i) {
        this->player_time_delta[i] = 0;
    }
}
