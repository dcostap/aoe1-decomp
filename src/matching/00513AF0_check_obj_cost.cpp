// VA: 00513AF0 TRIBE_Player::check_obj_cost | tplayer.cpp:1327-1406
// Attempt log:
// - baseline used decompiler-shaped pointer/boolean plumbing and was 7 bytes too large.
// - canonicalized ownership to TRIBE_Player::object_types (+0x24), resources (+0x50),
//   and ObjectType's 6-byte cost records anchored at the amount field (+0x14A).
// - moving the loop index declaration before the amount cursor reproduces xor edi
//   before the cursor lea; the natural candidate is now exact size and 4 bytes off.
// - expression/comparison/guard spellings and a focused FPU lab did not change the
//   remaining four-byte fld-st0 versus fld-resource/fadd-st1 hunk. A resources local
//   and a named total were rejected as broad or farther codegen.
// - a second focused arithmetic lab found exact output when the population operand
//   is explicitly left-associated with a folded zero; both +/- zero forms emit the
//   oracle's fld st0/fadd-resource pair. Keep the simpler population + 0.0f anchor.

struct ObjectCost {
    short type;
    short amount;
    unsigned char paid;
    unsigned char gap_05;
};

struct ObjectType {
    virtual ~ObjectType();
    unsigned char status;
    char gap_005[0x143];
    ObjectCost costs[3];
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    char gap_004[0x20];
    ObjectType** object_types;
    char gap_028[0x28];
    float* resources;

    unsigned char check_obj_cost(short obj_id, short* out, float factor, int skip_farm);
};

unsigned char TRIBE_Player::check_obj_cost(short obj_id, short* out, float factor, int skip_farm)
{
    float population = this->resources[3];
    if (out != 0) {
        *out = -1;
    }

    bool population_available;
    if (this->resources[29] < 1.0) {
        population = 0.0f;
        population_available = false;
    } else {
        population_available = true;
    }

    ObjectType* object = this->object_types[obj_id];
    if (object == 0 || object->status < 0x46) {
        if (out != 0) {
            *out = -1;
        }
        return 0;
    }

    int i = 0;
    short* amount_ptr = &object->costs[0].amount;
    for (; i < 3; ++i, amount_ptr += 3) {
        int type = amount_ptr[-1];
        if (type >= 0) {
            int amount_value = amount_ptr[0];
            float amount = (float)amount_value * factor;

            if (type == 4 && skip_farm == 0) {
                if (!(this->resources[11] < this->resources[32])) {
                    if (out == 0) {
                        return 0;
                    }
                    *out = 0x20;
                    return 0;
                }
            }

            if (population_available && type == 3) {
                population -= amount;
                if (population < 0.0f) {
                    if (out == 0) {
                        return 0;
                    }
                    *out = 3;
                    return 0;
                }
            }

            if (this->resources[type] < amount) {
                if (type != 4 || skip_farm == 0) {
                    unsigned char paid = *((unsigned char*)amount_ptr + 2);
                    if (paid == 0 || (population + 0.0f) + this->resources[type] < amount) {
                        if (out == 0) {
                            return 0;
                        }
                        *out = (short)type;
                        return 0;
                    }
                    population = population - (amount - this->resources[type]);
                }
            }
        }
    }
    return 1;
}
