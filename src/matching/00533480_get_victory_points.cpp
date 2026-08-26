#ifndef VICTORY_CONTEXT_H
class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    char gap_0[0x18];
    int field_1C;
    long get_victory_points();
};
#endif

long RGE_Victory_Conditions::get_victory_points() { return this->field_1C; }
