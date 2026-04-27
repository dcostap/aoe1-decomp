// attempt 1: tiny static-init helper for attackMap at 0x86BC60
// target shape: call InfluenceMap::InfluenceMap(0x32, 0x32, 0) on the global and return

class InfluenceMap {
public:
    InfluenceMap(int xSize, int ySize, unsigned char unchangeableLimit);
};

InfluenceMap* const attackMap = (InfluenceMap*)0x86BC60;

void $E19(void) {
    attackMap->InfluenceMap::InfluenceMap(0x32, 0x32, 0);
}
