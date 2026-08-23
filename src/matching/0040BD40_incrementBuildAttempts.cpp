#ifndef AICONMOD_CANONICAL_TU
class ConstructionItem {
public:
    void incrementBuildAttempts(void);
};

class ConstructionAIModule {
public:
    virtual void incrementBuildAttempts(float x, float y, int count);
    ConstructionItem* lot(float x, float y) const;
};
#endif

void ConstructionAIModule::incrementBuildAttempts(float x, float y, int count) {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && count > 0) {
        do {
            item->incrementBuildAttempts();
            count = count - 1;
        } while (count != 0);
    }
}
