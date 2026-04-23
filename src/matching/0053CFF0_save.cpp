extern "C" void __cdecl rge_write(int handle, void* buffer, int count);

class RGE_Unified_Visible_Map {
public:
    int mapWidth;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    void save(int handle);
};

void RGE_Unified_Visible_Map::save(int handle) {
    rge_write(handle, this, 4);
    rge_write(handle, &this->mapHeight, 4);
    if ((this->mapHeight > 0) && (this->mapWidth > 0)) {
        rge_write(handle, this->UnifiedVisibleMap, this->mapWidth * this->mapHeight * 4);
    }
}
