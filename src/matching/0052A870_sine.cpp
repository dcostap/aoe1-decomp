class TrigTable {
public:
    int normalize_index(int index);
    float table[1];

    float sine(int index);
};

float TrigTable::sine(int index) {
    return this->table[this->normalize_index(index)];
}
