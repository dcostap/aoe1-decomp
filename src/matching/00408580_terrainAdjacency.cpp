class BuildItem {
public:
    char gap_00[0x90];
    int terrainAdjacencyValue[3];

    int terrainAdjacency(int index) const;
};

int BuildItem::terrainAdjacency(int index) const {
    if ((index >= 1) && (index <= 2)) {
        return this->terrainAdjacencyValue[index];
    }
    return -1;
}
