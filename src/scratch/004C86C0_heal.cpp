// VA: 004C86C0 TRIBE_Building_Object::heal
// left in scratch: behavior/calls modeled and pay_obj_cost arg surface corrected to (short,float,int),
// but remaining blocker is early x87 scheduling. Original keeps maxHp in ST1, then loads param,
// stores healRate into the param stack slot, uses `fmul st1; fidiv [esp+0C]; fst [esp+0C]`;
// VC5 keeps preloading param/hp and emits fxch/fdivp-heavy expression code. Tried named maxHpFloat,
// reversed compare algebra, volatile param, and positive pay branch; no exact basin yet.
// 2026-05-10 StarryZephyr pass: rechecked baseline, tried inlining healRate load (no change) and named
// `maxHpFloat` reused across scaling/clamp. maxHpFloat reduced edit diff but still preloaded hp and used
// fxch/fdivp-heavy FPU with shifted/truncated tail. Restored baseline.

class TRIBE_Player {
public:
    unsigned char pay_obj_cost(short type, float amount, int flag);
};

class TRIBE_Combat_Object {
public:
    unsigned char heal(float amount);
};

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    void* vtable;
    int id;
    void* master_obj;
    TRIBE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;

    unsigned char heal(float amount);
};

unsigned char TRIBE_Building_Object::heal(float amount) {
    void* master = this->master_obj;
    int maxHp = *(short*)((char*)master + 0x26);
    int healRate = *(short*)((char*)master + 0x15A);
    amount = (amount * maxHp) / healRate;
    if (amount + this->hp > (float)maxHp) {
        amount = (float)maxHp - this->hp;
    }
    if (this->owner->pay_obj_cost(*(short*)((char*)master + 0x10), amount / (float)(maxHp * 2), 0)) {
        return TRIBE_Combat_Object::heal(amount);
    }
    return 2;
}
