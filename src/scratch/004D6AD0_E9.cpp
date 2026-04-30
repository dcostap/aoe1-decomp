// attempt: tiny static-init helper for iMap at 0x86BC38
// target shape: call InfluenceMap::InfluenceMap(0xFE, 0xFE, 0) on the global and return

class InfluenceMap {
public:
    InfluenceMap(int xSize, int ySize, unsigned char unchangeableLimit);
};

InfluenceMap* const iMap = (InfluenceMap*)0x86BC38;

void $E9(void) {
    iMap->InfluenceMap::InfluenceMap(0xFE, 0xFE, 0);
}
