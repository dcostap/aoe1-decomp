#ifndef TACT_LST_CONTEXT_H
class RGE_Action_Object;

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    RGE_Action_List(RGE_Action_Object* object);
};

class TRIBE_Action_List : public RGE_Action_List {
public:
    TRIBE_Action_List(RGE_Action_Object* object);
};
#endif

TRIBE_Action_List::TRIBE_Action_List(RGE_Action_Object* object)
    : RGE_Action_List(object) {
}
