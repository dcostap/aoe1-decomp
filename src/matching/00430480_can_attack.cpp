#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Combat_Object {
public:
    unsigned char gap_04[0x1B8];
    float attack_timer;

    virtual unsigned char can_attack();
};
#endif

unsigned char RGE_Combat_Object::can_attack() {
    if (attack_timer > 0.0f) {
        return 0;
    }
    return 1;
}
