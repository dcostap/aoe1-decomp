// attempt 1: natural TRIBE_Player resource/cost check from decompiler/asm shape

class ObjDef { public: char gap_00[4]; unsigned char status; char gap_05[0x147]; short cost_type0; short cost_amount0; unsigned char cost_paid0; short cost_type1; short cost_amount1; unsigned char cost_paid1; short cost_type2; short cost_amount2; unsigned char cost_paid2; };
class PlayerInfo { public: float resources[0x30]; char gap_c0[0]; };
class TRIBE_Player {
public:
    char gap_00[0x24];
    ObjDef** obj_defs;
    char gap_28[0x28];
    PlayerInfo* info;
    unsigned char check_obj_cost(short obj_id, short* lacking, float multiplier, int allow_house);
};

unsigned char TRIBE_Player::check_obj_cost(short obj_id, short* lacking, float multiplier, int allow_house) {
    float pop = this->info->resources[3];
    if (lacking) *lacking = -1;
    PlayerInfo* pi = this->info;
    if (pi->resources[29] < 0.0) {
        pop = 0.0f;
        lacking = (short*)0;
    } else {
        lacking = (short*)1;
    }
    ObjDef* def = this->obj_defs[obj_id];
    if (def == 0 || def->status < 0x46) {
        if (lacking) *lacking = -1;
        return 0;
    }
    char* p = (char*)&def->cost_type0;
    for (int i = 0; i < 3; ++i, p += 6) {
        short type = *(short*)p;
        if (type >= 0) {
            int amount_i = *(short*)(p + 2);
            float amount = (float)amount_i * multiplier;
            if (type == 4 && !allow_house) {
                if (!(pi->resources[11] < pi->resources[32])) {
                    if (lacking) *lacking = 0x20;
                    return 0;
                }
            }
            if ((char)lacking && type == 3) {
                pop -= amount;
                if (pop < 0.0f) {
                    if (lacking) *lacking = 3;
                    return 0;
                }
            }
            if (pi->resources[type] < amount) {
                if (type != 4 || !allow_house) {
                    if (*(unsigned char*)(p + 4) && !(pop + pi->resources[type] < amount)) {
                        pop = amount - pi->resources[type];
                    } else {
                        if (lacking) *lacking = type;
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
