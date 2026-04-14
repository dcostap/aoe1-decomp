class AIPlayStatus {
public:
    char gap_0[0x1A4];
    int arr_[5];
    int originalHitPoints(int index);
};

int AIPlayStatus::originalHitPoints(int index) {
    if (index < 0 || index >= 5) return -1;
    return this->arr_[index];
}
