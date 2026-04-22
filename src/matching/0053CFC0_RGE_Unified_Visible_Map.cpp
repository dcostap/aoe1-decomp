extern "C" void __cdecl free(void* block);

class RGE_Unified_Visible_Map {
public:
    void* gap_00;
    int mapHeight;
    unsigned long* UnifiedVisibleMap;

    void Set_Map_Offsets();
    ~RGE_Unified_Visible_Map();
};

RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map() {
    this->mapHeight = 0;
    Set_Map_Offsets();
    if (this->UnifiedVisibleMap != 0) {
        free(this->UnifiedVisibleMap);
    }
}
