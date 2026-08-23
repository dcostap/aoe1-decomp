#include "../../include/tscenaro_context.h"

#if 0
struct Inner_0052BA80 {
    void update();
};

class T_Scenario {
public:
    char gap_0[0x4];
    Inner_0052BA80 *ptr_;
    void update();
};
#endif

void T_Scenario::update() {
    this->time_line->update();
}
