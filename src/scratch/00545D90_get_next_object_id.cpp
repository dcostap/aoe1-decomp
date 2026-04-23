// first pass: direct scenario flag fast path plus scan for the next free object slot
// first build was wrong on the field layout; the remaining question is whether the loop lands in the original esi-save basin
// after layout fixes, the only stable drift left is the entry branch sense and prolog register ordering around max/next_object_id

class RGE_Static_Object;

class RGE_Game_World {
public:
    char gap_00[0x68];
    int next_object_id;
    char gap_6C[0x4];
    int scenario_object_id;
    unsigned char scenario_object_flag;
    char gap_75[0x13];
    RGE_Static_Object** objectsValue;
    char gap_8C[0x4];
    int maxNumberObjectsValue;

    long get_next_object_id();
};

long RGE_Game_World::get_next_object_id() {
    if (scenario_object_flag == 0) {
        int limit = maxNumberObjectsValue + -1;
        if (next_object_id <= limit) {
            do {
                if (objectsValue[next_object_id] == 0) {
                    break;
                }
                next_object_id = next_object_id + 1;
            } while (next_object_id <= limit);
        }

        int object_id = next_object_id;
        next_object_id = object_id + 1;
        return object_id;
    }

    return scenario_object_id;
}
