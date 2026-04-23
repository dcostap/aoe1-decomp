class TechnologyItem {
public:
    void* vtable_ptr;
    TechnologyItem* next;
    TechnologyItem* prev;
    int idValue;

    int id();
};

class ResearchAIModule {
public:
    char gap_00[0xF4];
    TechnologyItem techTree;

    TechnologyItem* item(int tech_id);
};

TechnologyItem* ResearchAIModule::item(int tech_id)
{
    TechnologyItem* item = this->techTree.next;
    TechnologyItem* end = &this->techTree;

    while (item != end) {
        if (item == 0)
            return 0;
        if (item->id() == tech_id)
            return item;
        item = item->next;
    }

    return 0;
}
