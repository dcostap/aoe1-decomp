// VA: 00417640 importantObject (56B)
// aiuaimod.cpp - linear search through importantObjects array

class UnitAIModule {
public:
    char gap_00[0x124];
    int* importantObjects;       // +0x124
    int numberImportantObjects;  // +0x128

    int importantObject(int obj);
};

int UnitAIModule::importantObject(int obj) {
    int count = this->numberImportantObjects;
    if (count <= 0) return 0;

    int* ptr = this->importantObjects;
    int i = 0;
    do {
        if (*ptr++ == obj) return 1;
        i++;
    } while (i < count);
    return 0;
}
