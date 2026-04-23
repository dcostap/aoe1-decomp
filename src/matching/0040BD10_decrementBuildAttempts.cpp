class ConstructionItem {
public:
    void decrementBuildAttempts(void);
};

class ConstructionAIModule {
public:
    virtual void decrementBuildAttempts(float x, float y, int count) const;
    ConstructionItem* lot(float x, float y) const;
};

void ConstructionAIModule::decrementBuildAttempts(float x, float y, int count) const {
    ConstructionItem* item = this->lot(x, y);
    if (item != 0 && count > 0) {
        do {
            item->decrementBuildAttempts();
            count = count - 1;
        } while (count != 0);
    }
}
