#include "../../include/airesmod_context.h"

void ResourceAIModule::decrementResources(ResourceItem* param_1) {
    int iVar1;
    int iVar2;

    if (param_1 != 0) {
        iVar1 = param_1->number();
        if (this->numberResourcesValue == iVar1) {
            iVar2 = 0;
            iVar1 = param_1->number();
            if (0 < iVar1) {
                do {
                    iVar1 = param_1->value(iVar2);
                    this->decrementResource(iVar2, iVar1);
                    iVar2 = iVar2 + 1;
                    iVar1 = param_1->number();
                } while (iVar2 < iVar1);
            }
        }
    }
}
