#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
struct ManagedArray_Int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIModule {
public:
    void* vftable;
    char pad[0xEC];
};

struct RGE_Player;

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray_Int objects;

    int removeObject(int objectId);
};
#endif

int MainDecisionAIModule::removeObject(int objectId) {
    int i = 0;
    while (i < this->objects.maximumSizeValue) {
        if (this->objects.value[i] == objectId) {
            break;
        }
        i++;
    }
    if (i >= this->objects.maximumSizeValue) {
        return 0;
    }
    while (i < this->objects.maximumSizeValue - 1) {
        this->objects.value[i] = this->objects.value[i + 1];
        i++;
    }
    int count = this->objects.numberValue - 1;
    this->objects.numberValue = count;
    if (count < 0) {
        this->objects.numberValue = 0;
    }
    return 1;
}
