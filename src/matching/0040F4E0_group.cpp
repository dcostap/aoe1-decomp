struct AIPlay_Item_0040F4E0 {
    char data[12];
};

class AIPlay {
public:
    char gap_0[0x53];
    AIPlay_Item_0040F4E0 items_[5];
    AIPlay_Item_0040F4E0 *group(int index);
};

AIPlay_Item_0040F4E0 *AIPlay::group(int index) {
    if (index < 0 || index >= 5) return 0;
    return &this->items_[index];
}
