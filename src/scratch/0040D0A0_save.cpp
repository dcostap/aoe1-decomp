// attempt 6: 224 vs 218 bytes, 6 bytes too large
// attempt 1: 208, for-loop with cached count, EBP counter
// attempt 2: 192, do-while too small
// attempt 3: 208, reusing count var
// attempt 4: 208, reading member in loop cond
// attempt 5: 224, decompiler-style with local temp, closer
// attempt 6: 224, growth check uses maximumSizeValue - 1 < i
// tried: various loop forms (for, do-while), various growth conditions, reading count from member vs stack
// tried: writing to local temp before rge_write (like decomp), direct member access
// PAUSED: 6-byte gap from VC5 register allocation (ebp vs edx for hFile, extra prologue pushes)
// The growth pattern causes VC5 to use different register allocation than original

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

    int save(int hFile);
};

void rge_write(int hFile, const void* buffer, int count);
void operator_delete(void* ptr);
void* operator_new(unsigned int size);

int MainDecisionAIModule::save(int hFile) {
    int count = this->objects.numberValue;
    rge_write(hFile, &count, 4);

    int i = 0;
    if (this->objects.numberValue > 0) {
        do {
            if (this->objects.maximumSizeValue - 1 < i) {
                count = this->objects.numberValue + 1;
                int* newArray = (int*)operator_new(count * 4);
                if (newArray != 0) {
                    for (int j = 0; j < this->objects.maximumSizeValue; j++) {
                        newArray[j] = this->objects.value[j];
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = newArray;
                    this->objects.maximumSizeValue = count;
                }
            }
            count = this->objects.value[i];
            rge_write(hFile, &count, 4);
            i++;
        } while (i < this->objects.numberValue);
    }
    return 1;
}
