#ifndef AICONMOD_CANONICAL_TU
class ConstructionItem {
public:
    void decrementBuildAttempts(void);
};

class ConstructionAIModule {
public:
    virtual void decrementBuildAttempts(float x, float y, int count);
    ConstructionItem* lot(float x, float y) const;
};
#endif

void ConstructionAIModule::decrementBuildAttempts(float x, float y, int count) {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && count > 0) {
        do {
            item->decrementBuildAttempts();
            count = count - 1;
        } while (count != 0);
    }
}
