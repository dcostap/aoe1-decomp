#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_00[0x8];
    RGE_Game_World* world;

    RGE_Static_Object* get_object_pointer(int index);
};
#endif

RGE_Static_Object* T_Scenario::get_object_pointer(int index) {
    RGE_Static_Object* result = 0;
    if (index > 0) {
        result = this->world->object(index - 1);
    }
    return result;
}
