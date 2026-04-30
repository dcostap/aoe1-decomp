// attempt: tiny static-init helper for losMap at 0x86BC10
// target shape: call InfluenceMap::InfluenceMap(0x32, 0x32, 0) on the global and return

class InfluenceMap {
public:
    InfluenceMap(int xSize, int ySize, unsigned char unchangeableLimit);
};

InfluenceMap* const losMap = (InfluenceMap*)0x86BC10;

void $E14(void) {
    losMap->InfluenceMap::InfluenceMap(0x32, 0x32, 0);
}
