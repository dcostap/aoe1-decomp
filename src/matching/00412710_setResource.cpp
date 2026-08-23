// attempt 1: initial draft, mismatch at offset 21, bad call signature
// attempt 2: define strings, fix logCommonHistory call order

#include "../../include/airesmod_context.h"

extern char s_setResource_n_v[];
extern char s_setResource_r_v[];

void ResourceAIModule::setResource(int index, int value) {
    this->logCommonHistory(s_setResource_n_v, index, value);
    if (index >= 0 && index < numberResourcesValue) {
        resourceValue[index] = value;
        this->logCommonHistory(s_setResource_r_v, index, resourceValue[index]);
    }
}
