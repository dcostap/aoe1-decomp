// first pass: write zone_map_num, then save each zone map through the pointer table
// tried a direct this->member form; the remaining mismatch was in the prolog register order
// tried a map-pointer alias; that moved the mismatch deeper and changed the loop addressing shape
// next probe: use the decompiler-style local pointer spelling with late init for the loop counter

extern "C" void __cdecl rge_write(int handle, void* buffer, int count);

class RGE_Zone_Map {
public:
    void save(int param);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    int zone_map_num;
    void* map;

    void save(int param);
};

void RGE_Zone_Map_List::save(int param) {
    int* count;
    int i;

    count = &zone_map_num;
    rge_write(param, count, 4);

    if (0 < *count) {
        i = 0;
        do {
            zone_maps[i]->save(param);
            ++i;
        } while (i < *count);
    }
}
