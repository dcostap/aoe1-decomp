class TrigTable {
public:
    int normalize_index(int index);
    char gap_0[0xC000];
    float table[1];

    float atangent(int index);
};

float TrigTable::atangent(int index) {
    return this->table[this->normalize_index(index)];
}
