// VA: 00413A20 UnitAIModule::attackingUnitID

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

class UnitAIModule {
public:
    char gap_00[0x60];
    int* attackingValues;
    int attackingNumber;
    char gap_68[4];
    int attackingMax;

    int attackingUnitID(int index);
};

int UnitAIModule::attackingUnitID(int index) {
    if (index < 0 || index >= this->attackingNumber) {
        return -1;
    }
    if (index > this->attackingMax - 1) {
        int newMax = index + 1;
        int* newValues = (int*)operator new(newMax * 4);
        if (newValues != 0) {
            int oldMax = this->attackingMax;
            int i = 0;
            if (oldMax > 0) {
                do {
                    if (i < newMax) {
                        i++;
                        int value = this->attackingValues[i - 1];
                        newValues[i - 1] = value;
                        oldMax = this->attackingMax;
                    } else {
                        break;
                    }
                } while (i < oldMax);
            }
            operator delete(this->attackingValues);
            this->attackingValues = newValues;
            this->attackingMax = newMax;
        }
    }
    return this->attackingValues[index];
}
