#include "../../include/tact_rep_context.h"

int TRIBE_Action_Repair::stop() {
    this->set_state(2);
    return 1;
}
