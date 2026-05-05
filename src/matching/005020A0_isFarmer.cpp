// Function: TribeTacticalAIModule::isFarmer
// VA: 005020A0
// Source: taitacmd.cpp lines 12502-12511
// Attempt log:
// - Replaced the old extern-c/cdecl stub with the real member-function surface.
//   VC5 does not need an explicit __thiscall keyword for C++ member functions;
//   declaring RGE_Static_Object::unitAI() and UnitAIModule::currentAction() as
//   non-virtual members gives the original ECX=this direct-call shape.

class UnitAIModule {
public:
    int currentAction();
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0c[0x68];
    UnitAIModule* unitAI();
};

class TribeTacticalAIModule {
public:
    int isFarmer(RGE_Static_Object* obj);
};

int TribeTacticalAIModule::isFarmer(RGE_Static_Object* obj)
{
    UnitAIModule* ai;
    int action;

    if (obj != 0 && (ai = obj->unitAI()) != 0 && obj->master_obj->id == 0x103) {
        ai = obj->unitAI();
        action = ai->currentAction();
        if (action != 0x261) {
            ai = obj->unitAI();
            action = ai->currentAction();
            if (action != 0x262) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
