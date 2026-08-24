#ifndef TAICONMD_SHARED_CONTEXT
class ConstructionItem {
public:
    int buildAttempts(void);
};

class TribeConstructionAIModule {
public:
    ConstructionItem* compare(ConstructionItem* a, ConstructionItem* b);
};
#endif

ConstructionItem* TribeConstructionAIModule::compare(ConstructionItem* a, ConstructionItem* b) {
    if (a->buildAttempts() > b->buildAttempts()) {
        return b;
    }
    return a;
}
