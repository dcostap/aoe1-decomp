// VA: 00413A20 UnitAIModule::attackingUnitID

#include "../../include/aiuaimod_context.h"

int UnitAIModule::attackingUnitID(int index) {
    if (index < 0 || index >= this->attackingUnitsValue.numberValue) {
        return -1;
    }
    if (index > this->attackingUnitsValue.maximumSizeValue - 1) {
        int newMax = index + 1;
        int* newValues = (int*)operator_new(newMax * 4);
        if (newValues != 0) {
            int oldMax = this->attackingUnitsValue.maximumSizeValue;
            int i = 0;
            if (oldMax > 0) {
                do {
                    if (i < newMax) {
                        i++;
                        int value = this->attackingUnitsValue.value[i - 1];
                        newValues[i - 1] = value;
                        oldMax = this->attackingUnitsValue.maximumSizeValue;
                    } else {
                        break;
                    }
                } while (i < oldMax);
            }
            operator_delete(this->attackingUnitsValue.value);
            this->attackingUnitsValue.value = newValues;
            this->attackingUnitsValue.maximumSizeValue = newMax;
        }
    }
    return this->attackingUnitsValue.value[index];
}
