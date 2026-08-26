// attempt 1: direct EH-framed new-expression for the victory object helper
// result: default flags were too small; /GX is justified here
// attempt 2: restore the 0x20 victim object surface so operator new gets the right size

#ifndef PLAYER_GROUPED_TU
class RGE_Player {
public:
    char gap_0[0x34];
    class RGE_Victory_Conditions* victory_conditions;

    virtual void new_victory();
};

class RGE_Victory_Conditions {
public:
    char pad_04[0x20 - 0x4];

    RGE_Victory_Conditions(RGE_Player* player);
};
#endif

void RGE_Player::new_victory() {
    RGE_Victory_Conditions* victory = new RGE_Victory_Conditions(this);
    this->victory_conditions = victory;
}
