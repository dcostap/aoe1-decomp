class TrigTable {
public:
    int normalize_index_360(int index);
    char gap_0[0x10B40];
    float table[1];

    float tan360(int index);
};

float TrigTable::tan360(int index) {
    return this->table[this->normalize_index_360(index)];
}
