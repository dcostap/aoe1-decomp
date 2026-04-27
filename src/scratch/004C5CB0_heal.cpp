// attempt log:
// first pass: natural heal/clamp/cap spelling with a local hp total and direct compare to master max
// second pass: remove locals and spell the clamp with direct member writes / compares to chase the VC5 FPU basin
// third pass: mirror the decompiler shape more literally with fVar1 / int max_hp locals and the short->int cast
// fourth pass: split the low-clamp into a nested negative-check block to probe the FPU compare order
// fifth pass: gate the addition itself behind the negative check to see whether VC5 wants the compare first
// target shape: add amount to hp, clamp low to 1.0 on negative underflow, then cap at master max hp
// paused here: 5 tries in, but VC5 still wants a different early FPU compare/call ordering than the natural source shapes

class RGE_Master_Static_Object {
public:
    char gap_00[0x26];
    short hp;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x24];
    float hp;

    unsigned char heal(float amount);
};

unsigned char RGE_Static_Object::heal(float amount) {
    if (amount < 0.0f) {
        this->hp += amount;
        if (this->hp < 1.0f) {
            this->hp = 1.0f;
        }
    } else {
        this->hp += amount;
    }

    int max_hp = (int)this->master_obj->hp;
    if (this->hp < (float)max_hp) {
        return 0;
    }

    this->hp = (float)max_hp;
    return 1;
}
