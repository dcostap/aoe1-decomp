#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x70];
    int field_74;
    int unitAI();
};
#endif

UnitAIModule* RGE_Static_Object::unitAI() { return this->unitAIValue; }
