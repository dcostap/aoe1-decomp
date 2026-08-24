#ifndef TACT_WND_CONTEXT_H
class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(RGE_Action_Object* object, int flag);
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    short field_04;
    char gap_06[0x26];
    int field_2C;

    TRIBE_Action_Wonder(RGE_Action_Object* object);
};
#endif

TRIBE_Action_Wonder::TRIBE_Action_Wonder(RGE_Action_Object* object)
    : RGE_Action(object, 1) {
    this->field_04 = 0x78;
    this->field_2C = 0;
}
