struct MapTile { char gap_00[5]; unsigned char type; char gap_06[0x12]; };
struct MapContainer { MapTile* tiles; };
class RGE_RMM_Elevation_Generator {
public:
    char gap_00[0x10];
    MapContainer* map;
    int width;
    int height;
    long count_map_tiles(unsigned char value);
};
long RGE_RMM_Elevation_Generator::count_map_tiles(unsigned char value) {
    MapContainer* map = this->map;
    long count = 0;
    MapTile* tile = map->tiles;
    MapTile* end = tile + (this->width * this->height);
    while (tile < end) {
        if ((tile->type & 0x1F) == value) {
            count++;
        }
        tile++;
    }
    return count;
}
