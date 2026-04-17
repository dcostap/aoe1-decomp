// STATUS: blocked
// BLOCKER: VC5 keeps using integer mov/mov stores for the float copy instead of the original fld/fstp pair, despite the source and destination offsets being correct
// NOTE: layout is understood (`combat_data` at +8, source float at +0x120, attack_timer at +0x1BC); remaining drift is pure float-move codegen

class CombatData {
public:
    char gap_00[0x120];
    float attack_timer_reset;
};

class RGE_Combat_Object {
public:
    char gap_00[0x08];
    CombatData* combat_data;
    char gap_0C[0x1B0];
    float attack_timer;

    void reset_attack_timer(void);
};

void RGE_Combat_Object::reset_attack_timer(void) {
    attack_timer = *(volatile float*)&combat_data->attack_timer_reset;
}
