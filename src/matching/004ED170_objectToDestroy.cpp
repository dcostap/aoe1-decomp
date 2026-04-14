class TacticalAIGroup {
public:
    char gap_0[0x2D0];
    int arr_[20];
    int objectToDestroy(int index);
};

int TacticalAIGroup::objectToDestroy(int index) {
    if (index < 0 || index >= 20) return -1;
    return this->arr_[index];
}
