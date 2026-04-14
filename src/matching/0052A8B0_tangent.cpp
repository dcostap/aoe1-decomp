class TrigTable {
public:
    int normalize_index(int index);
    char gap_0[0x8000];
    float table[1];

    float tangent(int index);
};

float TrigTable::tangent(int index) {
    return this->table[this->normalize_index(index)];
}
