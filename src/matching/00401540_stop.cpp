#include "../../include/act_atak_context.h"

int RGE_Action_Attack::stop(void) {
    this->set_state(1);
    return 1;
}
