class TrigTable {
public:
    int normalize_index_360(int index);
    char gap_0[0x10000];
    float table[1];

    float sin360(int index);
};

float TrigTable::sin360(int index) {
    return this->table[this->normalize_index_360(index)];
}
