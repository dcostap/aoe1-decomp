#ifndef VICTORY_CONTEXT_H
class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    int field_4;
    int field_8;
    long condition_number(long p0);
};
#endif

long RGE_Victory_Conditions::condition_number(long p0) { return this->field_8; }
