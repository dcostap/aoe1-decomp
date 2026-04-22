class TacticalAIGroup {
public:
    char gap_00[0x2CC];
    int numberObjectsToDestroy;
    int objectsToDestroy[19];

    int addObjectToDestroy(int objectId);
};

int TacticalAIGroup::addObjectToDestroy(int objectId) {
    if (this->numberObjectsToDestroy < 0x13) {
        this->objectsToDestroy[this->numberObjectsToDestroy] = objectId;
        this->numberObjectsToDestroy = this->numberObjectsToDestroy + 1;
        return 1;
    }
    return 0;
}
