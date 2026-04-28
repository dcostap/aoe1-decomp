// 0053CF10 RGE_Unified_Visible_Map::load
// Attempt 2: remove decompiler-invented piVar1, use direct field access

extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Unified_Visible_Map {
public:
    int mapWidth;              // +0x00
    int mapHeight;             // +0x04
    unsigned long* UnifiedVisibleMap;  // +0x08

    void load(int handle);
};

void RGE_Unified_Visible_Map::load(int handle) {
    int oldH = this->mapHeight;
    int oldW = this->mapWidth;

    rge_read(handle, this, 4);
    rge_read(handle, &this->mapHeight, 4);
    if ((0 < this->mapHeight) && (0 < this->mapWidth)) {
        if ((oldW != this->mapWidth) || (oldH != this->mapHeight)) {
            if (this->UnifiedVisibleMap != 0) {
                free(this->UnifiedVisibleMap);
            }
            this->UnifiedVisibleMap = (unsigned long*)calloc(this->mapHeight * this->mapWidth, 4);
        }
        rge_read(handle, this->UnifiedVisibleMap, this->mapHeight * this->mapWidth * 4);
        return;
    }
    this->mapHeight = 0;
    this->UnifiedVisibleMap = 0;
    this->mapWidth = 0;
}
