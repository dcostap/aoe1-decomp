// attempt: tiny static-init helper for iMap at 0x86BC38
// target shape: call InfluenceMap::InfluenceMap(0xFE, 0xFE, 0) on the global and return

#ifndef TAIINFMD_PREFIX_CONTEXT
class InfluenceMap {
public:
    InfluenceMap(int xSize, int ySize, unsigned char unchangeableLimit);
};
#endif

InfluenceMap* const iMap = (InfluenceMap*)0x86BC38;

void $E9(void) {
    iMap->InfluenceMap::InfluenceMap(0xFE, 0xFE, 0);
}

// Compiler-generated static initializer from taiinfmd.cpp line 104.
InfluenceMap* const losMap = (InfluenceMap*)0x86BC10;

void $E14(void) {
    losMap->InfluenceMap::InfluenceMap(0x32, 0x32, 0);
}
