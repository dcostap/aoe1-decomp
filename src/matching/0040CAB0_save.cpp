void rge_write(int file, void* data, int size);

class EmotionalAIModule {
public:
    char gap_00[0xF4];
    int stateValue[6];

    int save(int file);
};

int EmotionalAIModule::save(int file) {
    int* value = this->stateValue;
    int count = 6;

    do {
        rge_write(file, value, 4);
        value = value + 1;
        count = count - 1;
    } while (count != 0);
    return 1;
}
