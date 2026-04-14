class TrigTable {
public:
    int normalize_index(int index);
    char gap_0[0x4000];
    float table[1];

    float cosine(int index);
};

float TrigTable::cosine(int index) {
    return this->table[this->normalize_index(index)];
}
