// VA: 00513C50 TRIBE_Player::pay_obj_cost
// tplayer.cpp:1410-1445

struct ObjectType { char gap_000[0x14C]; unsigned char first_paid; };
class TRIBE_Player {
public:
    char gap_000[0x24]; ObjectType** object_types; char gap_028[0x28]; float* resources;
    unsigned char check_obj_cost(short obj_id, short* out, float factor, int skip_farm);
    unsigned char pay_obj_cost(short obj_id, float factor, int skip_farm);
};

unsigned char TRIBE_Player::pay_obj_cost(short obj_id, float factor, int skip_farm)
{
    int save_skip = skip_farm;
    if (check_obj_cost(obj_id, 0, factor, skip_farm)) {
        ObjectType* object_type = object_types[obj_id];
        for (int i = 0; i < 3; ++i) {
            unsigned char* cost = &object_type->first_paid + i * 6;
            int type = *(short*)(cost - 4);
            if (type >= 0 && *cost != 0 && (!save_skip || type != 4)) {
                int amount = *(short*)(cost - 2);
                float value = (float)amount * factor;
                float* res = resources;
                if (value > res[type]) {
                    res[3] = res[3] - (value - res[type]);
                    resources[type] = 0.0f;
                } else {
                    res[type] = res[type] - value;
                }
            }
        }
        return 1;
    }
    return 0;
}
