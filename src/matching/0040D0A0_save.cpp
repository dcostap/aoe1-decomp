// attempt 7: managed-array save with combined growth-copy condition

void rge_write(int hFile, const void* buffer, int count);
void* operator new(unsigned int);
void operator delete(void*);

#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
class MainDecisionAIModule {
public:
    char gap_000[0xF4];
    long* object_ids;
    long object_count;
    char gap_0FC[4];
    long object_capacity;
    int save(int hFile);
};
#endif

int MainDecisionAIModule::save(int hFile) {
    int temp = this->objects.numberValue;
    rge_write(hFile, &temp, 4);

    int i = 0;
    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int newCapacity = i + 1;
                int* newIds = (int*)operator new(newCapacity * 4);
                if (newIds != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < newCapacity) {
                        newIds[j] = this->objects.value[j];
                        ++j;
                    }
                    operator delete(this->objects.value);
                    this->objects.value = newIds;
                    this->objects.maximumSizeValue = newCapacity;
                }
            }
            temp = this->objects.value[i];
            rge_write(hFile, &temp, 4);
            ++i;
        } while (i < this->objects.numberValue);
    }
    return 1;
}
