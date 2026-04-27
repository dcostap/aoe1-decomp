// VA: 00458600 load_terrain_obj_types (341B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void load_terrain_obj_types(const char* filename);
};

int __cdecl sub_0054BBA0(const char* filename, int mode);

void RGE_Map::load_terrain_obj_types(const char* filename) {
    int fd = sub_0054BBA0(filename, 0x57F320);
    if (fd == -1) return;
    
    field_8 = fd;
}
