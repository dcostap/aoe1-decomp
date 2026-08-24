#ifndef TACT_WND_CONTEXT_H
class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(int id, RGE_Action_Object* object, int flag);
};

class TRIBE_Action_Wonder : public RGE_Action {
public:
    short field_04;

    TRIBE_Action_Wonder(int id, RGE_Action_Object* object);
};
#endif

TRIBE_Action_Wonder::TRIBE_Action_Wonder(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->field_04 = 0x78;
}
