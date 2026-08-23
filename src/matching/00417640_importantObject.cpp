#include "../../include/aiuaimod_context.h"

int UnitAIModule::importantObject(int obj) {
    int i = 0;
    int count = this->numberImportantObjects;

    if (count <= 0) {
        return 0;
    }

    while (i < count) {
        if (this->importantObjects[i] == obj) {
            return 1;
        }
        i++;
    }

    return 0;
}
