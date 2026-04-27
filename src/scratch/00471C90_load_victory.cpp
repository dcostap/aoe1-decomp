// first pass: EH-framed allocation helper that stores the constructed victory object back to the player
// if this is sticky, the remaining lead is probably just the ctor signature / /GX basin rather than the store itself
// tried direct new + local temp; VC5 still hoisted the store into the success arm
// tried placement-new / operator_new shape; it blew up the TU size and was not worth forcing
// paused in scratch because the remaining mismatch is the store/branch basin around the EH/new helper
class RGE_Player;

class RGE_Victory_Conditions {
public:
    void* vtable_ptr;
    char pad_04[0x20 - 0x4];

    RGE_Victory_Conditions(RGE_Player* player, int param_1, long* param_2, unsigned char param_3);
};

class RGE_Player {
public:
    char pad_00[0x34];
    RGE_Victory_Conditions* victory_conditions;

    void load_victory(int param_1, long* param_2, unsigned char param_3);
};

void RGE_Player::load_victory(int param_1, long* param_2, unsigned char param_3) {
    RGE_Victory_Conditions* victory;

    victory = new RGE_Victory_Conditions(this, param_1, param_2, param_3);
    this->victory_conditions = victory;
}
