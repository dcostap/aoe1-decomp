class EmotionalAIModule {
public:
    char gap_0[0xF4];
    int arr_[6];
    void setState(int index, int val);
};

void EmotionalAIModule::setState(int index, int val) {
    if (index < 0 || index >= 6) return;
    this->arr_[index] = val;
}
