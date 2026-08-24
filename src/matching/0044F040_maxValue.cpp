#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;

    int maxValue(void);
};
#endif

int InfluenceMap::maxValue(void) {
    int total = this->xSizeValue * this->ySizeValue;
    int maxVal = (unsigned int)this->valueValue[0];
    int index = 0;
    if (total > 0) {
        do {
            int val = (unsigned int)this->valueValue[index];
            if (val <= maxVal) {
                // keep current max
            } else {
                maxVal = val;
            }
            ++index;
        } while (index < total);
    }
    return maxVal;
}
