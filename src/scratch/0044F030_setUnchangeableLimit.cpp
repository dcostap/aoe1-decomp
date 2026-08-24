#ifndef INFMAP_SHARED_CONTEXT
class InfluenceMap {
public:
    char gap_0[0x24];
    unsigned char unchangeableLimitValue;
    void setUnchangeableLimit(unsigned char val);
};
#endif

void InfluenceMap::setUnchangeableLimit(unsigned char value) {
    if (value > 0)
        this->unchangeableLimitValue = value;
}
