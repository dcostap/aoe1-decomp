#ifndef ACT_TRAN_SHARED_CONTEXT
class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(int id, RGE_Action_Object* object, int flag);
};

class RGE_Action_Transport : public RGE_Action {
public:
    short field_04;

    RGE_Action_Transport(int id, RGE_Action_Object* object);
};
#endif

RGE_Action_Transport::RGE_Action_Transport(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->field_04 = 0x0C;
}
