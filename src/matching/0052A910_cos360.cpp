class TrigTable {
public:
    int normalize_index_360(int index);
    char gap_0[0x105A0];
    float table[1];

    float cos360(int index);
};

float TrigTable::cos360(int index) {
    return this->table[this->normalize_index_360(index)];
}
