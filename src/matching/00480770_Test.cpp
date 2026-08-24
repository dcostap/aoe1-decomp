#include "../../include/rge_tslc_context.h"

void RGE_TimeSinceLastCall::Test() {
    for (int i = 0; i < 100; i++) this->aTSLC[i] = 10;
}
