class ConstructionItem {
public:
    void incrementBuildAttempts(void);
};

class ConstructionAIModule {
public:
    virtual void incrementBuildAttempts(float x, float y, int count) const;
    ConstructionItem* lot(float x, float y) const;
};

void ConstructionAIModule::incrementBuildAttempts(float x, float y, int count) const {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && count > 0) {
        do {
            item->incrementBuildAttempts();
            count = count - 1;
        } while (count != 0);
    }
}
