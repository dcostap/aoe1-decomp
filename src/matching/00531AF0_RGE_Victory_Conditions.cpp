class RGE_Player;

class RGE_Victory_Conditions {
public:
    virtual void dummy();
    int field_4;
    int field_8;
    void* field_C;
    char field_10;
    char gap_11[3];
    int field_14;
    int field_18;
    int field_1C;

    RGE_Victory_Conditions(RGE_Player* player);
};

RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* player) {
    this->field_C = player;
    this->field_8 = 0;
    this->field_4 = 0;
    this->field_14 = 0;
    this->field_10 = 0;
    this->field_18 = 0;
    this->field_1C = 0;
}
