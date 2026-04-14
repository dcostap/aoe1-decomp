class TrigTable {
public:
    int normalize_index_360(int index);
    char gap_0[0x110E0];
    float table[1];

    float atan360(int index);
};

float TrigTable::atan360(int index) {
    return this->table[this->normalize_index_360(index)];
}
