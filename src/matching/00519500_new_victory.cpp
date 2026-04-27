// attempt log:
// first pass: EH-framed factory helper with a direct 0x20 new and assignment into this+0x34
// second pass: give the victim class an explicit 0x20 surface so VC5 emits the right allocation size
// target shape: allocate TRIBE_Victory_Conditions(0x20), call ctor with this, store result at +0x34 or 0 on alloc fail

class RGE_Player;
class TRIBE_Victory_Conditions;

class TRIBE_Player {
public:
    char gap_00[0x34];
    TRIBE_Victory_Conditions* victory;

    void new_victory(void);
};

class TRIBE_Victory_Conditions {
public:
    char pad_0[0x20];
    TRIBE_Victory_Conditions(RGE_Player* player);
};

void TRIBE_Player::new_victory(void) {
    TRIBE_Victory_Conditions* v = new TRIBE_Victory_Conditions((RGE_Player*)this);
    this->victory = v;
}
