#ifndef AICONMOD_CANONICAL_TU
class BuildItem;
class ConstructionItem;
class ConstructionAIModule {
public:
    virtual ~ConstructionAIModule();
    ConstructionItem* placeStructure(BuildItem* item);
};
#endif

// The PDB-qualified virtual surface is ConstructionItem* placeStructure(BuildItem*).
// The parameter and result are unused in this shipped base implementation.
ConstructionItem* ConstructionAIModule::placeStructure(BuildItem* item) {
    return 0;
}
