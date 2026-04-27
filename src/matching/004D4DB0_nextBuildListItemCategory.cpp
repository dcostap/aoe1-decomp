// attempt 1: sentinel/null build-list walk that returns the first acceptable build category
// exact match landed once the BuildItem next pointer was modeled at +0x6C and the reject-check order matched the asm

class BuildItem {
public:
    char gap_00[0x6C];
    BuildItem* next;

    int built() const;
    int inProgress() const;
    int skip() const;
    unsigned char permanentSkip() const;
    int buildCategory() const;
};

class TribeBuildAIModule {
public:
    char gap_00[0xF0];
    BuildItem buildList;

    int nextBuildListItemCategory();
};

int TribeBuildAIModule::nextBuildListItemCategory() {
    BuildItem* item = this->buildList.next;
    BuildItem* sentinel = &this->buildList;

    while (item != sentinel && item != 0) {
        if (item->built() == 0 && item->inProgress() == 0 && item->skip() != 1 && !item->permanentSkip()) {
            return item->buildCategory();
        }
        item = item->next;
    }

    return 0;
}
