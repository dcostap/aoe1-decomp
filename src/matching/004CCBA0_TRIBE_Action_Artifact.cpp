class RGE_Action_Object;

#ifndef AOE1_TACT_ART_TU_CONTEXT
class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(int id, RGE_Action_Object* object, int flag);
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    short field_04;

    TRIBE_Action_Artifact(int id, RGE_Action_Object* object);
};
#endif

TRIBE_Action_Artifact::TRIBE_Action_Artifact(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->field_04 = 0x6B;
}
