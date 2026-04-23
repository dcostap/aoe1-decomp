// tried a straight pointer scan and a count-hoisted loop; VC5 still adds an extra compare/jump in the loop body
// remaining gap is loop-shape/register-allocation drift, not behavior
class UnitAIModule {
public:
    char gap_00[0x124];
    int* importantObjects;
    int numberImportantObjects;

    int importantObject(int id);
};

int UnitAIModule::importantObject(int id) {
    int iVar1 = 0;
    if (this->numberImportantObjects <= 0) {
        return 0;
    }
    int* piVar2 = this->importantObjects;
    do {
        if (*piVar2 == id) {
            return 1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
    } while (iVar1 < this->numberImportantObjects);
    return 0;
}
