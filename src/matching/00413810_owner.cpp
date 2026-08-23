#include "../../include/aiuaimod_context.h"

RGE_Player* UnitAIModule::owner() const {
    return this->objectValue->owner;
}
