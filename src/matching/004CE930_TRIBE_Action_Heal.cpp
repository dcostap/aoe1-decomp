class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(int id, RGE_Action_Object* object, int flag);
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    short field_04;

    TRIBE_Action_Heal(int id, RGE_Action_Object* object);
};

TRIBE_Action_Heal::TRIBE_Action_Heal(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->field_04 = 0x69;
}
