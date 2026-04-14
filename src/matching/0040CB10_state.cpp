class EmotionalAIModule {
public:
    char gap_0[0xF4];
    int arr_[6];
    int state(int index);
};

int EmotionalAIModule::state(int index) {
    if (index < 0 || index >= 6) return -1;
    return this->arr_[index];
}
