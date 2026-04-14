struct InfluenceMap {
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    int valueValue;
    int** rowValue;
};

int __fastcall maxValue(InfluenceMap* self, int) {
    int maxVal = -1;
    for (int y = 0; y < self->ySizeValue; y++) {
        for (int x = 0; x < self->xSizeValue; x++) {
            int val = self->rowValue[y][x];
            if (val > maxVal)
                maxVal = val;
        }
    }
    return maxVal;
}
