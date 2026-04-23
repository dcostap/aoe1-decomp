// tried the direct sentinel-walk with operator== and setBuilt calls; body is close, but VC5 still picks the wrong early register basin
// tried moving the item temp later and inlining the end sentinel; mismatch stayed at the top compare/load window
// leaving in scratch because the remaining gap is the early prolog/register assignment shape, not a behavior mismatch
class ConstructionItem;

int __cdecl operator==(const ConstructionItem& a, const ConstructionItem& b);

class ConstructionItem {
public:
    char gap_00[0x6C];
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    void setBuilt(int v);
};

class ConstructionAIModule {
public:
    char gap_00[0xF4];
    ConstructionItem constructionLots;

    void setBuilt(ConstructionItem* item, int built);
};

void ConstructionAIModule::setBuilt(ConstructionItem* item, int built) {
    ConstructionItem* current;
    ConstructionItem* target;

    current = this->constructionLots.next;
    if (current != &this->constructionLots) {
        target = item;
        while (current != 0) {
            if (operator==(*current, *target) == 1) {
                current->setBuilt(built);
                return;
            }
            current = current->next;
            if (current == &this->constructionLots) {
                return;
            }
        }
    }
}
