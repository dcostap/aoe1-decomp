// attempt 1: UnitAIModule explore gate with direct currentAction test, object vtable call, and follow-up action/target helpers
// attempt 2: fixed the member offsets, but the function-pointer/vtable call basin still forces the wrong prolog shape; keeping this in scratch for now
#include "..\..\include\game_types.h"

class RGE_Static_Object {
public:
    void** vtable_ptr;
};

class UnitAIModule {
public:
    char gap_00[0x4];
    RGE_Static_Object* objectValue;
    char gap_08[0x28];
    int currentActionValue;

    void setCurrentAction(int value);
    void setCurrentTarget(int id, float x, float y, float z);
    int explore(int param_1, int param_2, int param_3);
};

int UnitAIModule::explore(int param_1, int param_2, int param_3) {
    typedef int (*ExploreFn)(RGE_Static_Object*, int, int, int);
    int p3;
    int result;

    p3 = param_3;
    if (p3 == 0 && this->currentActionValue != -1) {
        return 0;
    }

    result = ((ExploreFn)this->objectValue->vtable_ptr[0x17C / 4])(this->objectValue, param_1, param_2, p3);
    if (result != 1) {
        return 0;
    }

    this->setCurrentAction(0x25D);
    this->setCurrentTarget(-1, (float)param_2, (float)param_1, 1.0f);
    return 1;
}
