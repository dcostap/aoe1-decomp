class ResourceItem;

class TechnologyItem {
public:
    ResourceItem* resourceCost();
};

class ResearchAIModule {
public:
    TechnologyItem* item(int id);
    ResourceItem* resourceCost(int id);
};

ResourceItem* ResearchAIModule::resourceCost(int id) {
    TechnologyItem* tech = this->item(id);
    if (tech == 0) {
        return 0;
    }
    return tech->resourceCost();
}
