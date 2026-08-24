#include "../../include/tairesmd_context.h"

int TribeResourceAIModule::resource(int index) const {
    if ((index >= 0) && (index < this->numberResourcesValue)) {
        return (int)this->md->player->values[index];
    }
    return -1;
}
