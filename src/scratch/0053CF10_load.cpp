// tried the direct source shape; mismatch stayed at the allocation/read size operand order
// tried the decompiler-local temp order; no codegen change in the hot block
// tried one operand-order flip on the count expression; still non-exact, remaining gap is localized

extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    void load(int handle);
};

void RGE_Unified_Visible_Map::load(int handle) {
    int iVar2 = this->mapHeight;
    int iVar3 = this->mapWidth;
    int* piVar1 = &this->mapHeight;

    rge_read(handle, this, 4);
    rge_read(handle, piVar1, 4);
    if ((0 < *piVar1) && (0 < this->mapWidth)) {
        if ((iVar3 != this->mapWidth) || (iVar2 != *piVar1)) {
            if (this->UnifiedVisibleMap != 0) {
                free(this->UnifiedVisibleMap);
            }
            this->UnifiedVisibleMap = (unsigned long*)calloc(*piVar1 * this->mapWidth, 4);
        }
        rge_read(handle, this->UnifiedVisibleMap, *piVar1 * this->mapWidth * 4);
        return;
    }
    *piVar1 = 0;
    this->UnifiedVisibleMap = 0;
    this->mapWidth = 0;
}
