class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;
    char gap_70[0x10];
    int progressValue;
    int builtValue;

    int inProgress(void) const;
    int built(void) const;
};

class BuildAIModule {
public:
    char gap_00[0xF0];
    BuildItem buildList;

    int numberItemsBuilt(void) const;
};

int BuildAIModule::numberItemsBuilt(void) const {
    const BuildItem* current = this->buildList.next;
    const BuildItem* end = &this->buildList;
    int count = 0;
    while (current != end && current != 0) {
        if (current->built() == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}
