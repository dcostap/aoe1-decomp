#ifndef VICTORY_CONTEXT_H
class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    int field_4;
    int field_8;
    int condition_number(int p0);
};
#endif

int RGE_Victory_Conditions::condition_number(int p0) { return this->field_8; }
