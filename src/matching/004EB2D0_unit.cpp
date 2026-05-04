class TacticalAIGroup {
public:
    void* vtable_ptr;
    TacticalAIGroup* next;
    TacticalAIGroup* prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];

    int unit(int index);
};

int TacticalAIGroup::unit(int index) {
    int i = 0;
    int used = -1;
    int limit = index + 1;
    int* units = this->unitsValue;

    while (i < 0x28) {
        if (used >= limit) {
            goto too_far;
        }
        if (*units != -1) {
            used++;
        }
        if (used == index) {
            return this->unitsValue[i];
        }
        i++;
        units++;
    }
    return -1;

too_far:
    return -1;
}
