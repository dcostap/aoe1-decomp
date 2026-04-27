// ACCEPTED_DRIFT: constructor tail store-order drift only; the same vptr/type/tech/player fields are written after the same base-constructor call and before the same this return.
class RGE_Action_Object;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(RGE_Action_Object* object, int doSetup);

    unsigned short action_type;
    char gap_06[0x3A];
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    virtual void vf00(void);
    short tech_id;
    char gap_42[0x02];
    int unique_id;

    TRIBE_Action_Make_Tech(RGE_Action_Object* object, short tech_id, int unique_id);
};

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object* object, short tech_id, int unique_id)
    : RGE_Action(object, 1) {
    this->unique_id = unique_id;
    this->action_type = 0x67;
    this->tech_id = tech_id;
}
