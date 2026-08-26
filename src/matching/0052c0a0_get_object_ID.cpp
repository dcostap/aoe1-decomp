#include "../../include/tscenaro_context.h"

// BINARY NOTE: The PDB uses the private RGE_Static_Object* ABI. Its id is at
// offset 4 after the virtual base pointer.

#if 0
class T_Scenario {
public:
    virtual ~T_Scenario();

private:
    int get_object_ID(RGE_Static_Object* obj);
};
#endif

int T_Scenario::get_object_ID(RGE_Static_Object* obj) {
    return obj->id;
}
