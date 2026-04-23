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

    int numberItemsBuiltOrInProgress(void) const;
};

int BuildAIModule::numberItemsBuiltOrInProgress(void) const {
    const BuildItem* item = this->buildList.next;
    const BuildItem* end = &this->buildList;
    int count = 0;

    while (item != end && item != 0) {
        if (item->inProgress() == 1 || item->built() == 1) {
            count++;
        }
        item = item->next;
    }

    return count;
}
