// STATUS: active lead
// branch contents and field layout are now correct, but VC5 still wants the original lexical order: flag test, scenario-id path, then the normal decrement path at the tail
// next lead: force that exact layout with an explicit normal-path label so the `je` can land on the trailing block instead of reordering it earlier

class RGE_Game_World {
public:
    char gap_00[0x6C];
    long next_reusable_object_id;
    long scenario_object_id;
    unsigned char scenario_object_flag;

    long get_next_reusable_object_id();
};

long RGE_Game_World::get_next_reusable_object_id() {
    long id;

    if (this->scenario_object_flag == 0) {
        goto normal_path;
    }

    id = this->scenario_object_id;
    if (id >= this->next_reusable_object_id) {
        return id;
    }
    this->next_reusable_object_id = id - 1;
    return id;

normal_path:
    id = this->next_reusable_object_id;
    this->next_reusable_object_id = id - 1;
    return id;
}
