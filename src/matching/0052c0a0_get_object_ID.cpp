#include "../../include/tscenaro_context.h"

#if 0
struct ScenarioObj {
    int pad_00;
    int id_;
};

class T_Scenario {
public:
    virtual ~T_Scenario();

    int get_object_ID(ScenarioObj* obj);
};
#endif

int T_Scenario::get_object_ID(ScenarioObj* obj) {
    return obj->id_;
}
