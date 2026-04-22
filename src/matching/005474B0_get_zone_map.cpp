class RGE_Zone_Map;

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    int zone_map_num;

    RGE_Zone_Map* get_zone_map(long index);
};

RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(long index) {
    if (index < this->zone_map_num) {
        if (index >= 0) {
            return this->zone_maps[index];
        }
    }
    return 0;
}
