// RGE_Game_World::get_next_reusable_object_id - manage reusable object ID counter

class RGE_Game_World {
public:
    char gap_00[0x6C];
    long next_reusable_object_id;      // 0x6C
    long scenario_object_id;           // 0x70
    unsigned char scenario_object_flag; // 0x74

    long get_next_reusable_object_id();
};

long RGE_Game_World::get_next_reusable_object_id() {
    if (this->scenario_object_flag != 0) {
        long sid = this->scenario_object_id;
        if (sid < this->next_reusable_object_id) {
            this->next_reusable_object_id = sid - 1;
        }
        return sid;
    }

    return this->next_reusable_object_id--;
}
