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
    int temp = this->object_count;
    rge_write(hFile, &temp, 4);

    int i = 0;
    if (this->object_count > 0) {
        do {
            if (i > this->object_capacity - 1) {
                int newCapacity = i + 1;
                long* newIds = (long*)operator new(newCapacity * 4);
                if (newIds != 0) {
                    int j = 0;
                    while (j < this->object_capacity && j < newCapacity) {
                        newIds[j] = this->object_ids[j];
                        ++j;
                    }
                    operator delete(this->object_ids);
                    this->object_ids = newIds;
                    this->object_capacity = newCapacity;
                }
            }
            temp = this->object_ids[i];
            rge_write(hFile, &temp, 4);
            ++i;
        } while (i < this->object_count);
    }
    return 1;
}
