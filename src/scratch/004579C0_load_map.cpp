// VA: 004579C0 RGE_Map::load_map
// Attempt log:
// - Baseline uses the proven RGE_Map offsets, 24-byte RGE_Tile layout, old and
//   new file formats, zone-list replacement, and unified visibility loading.
// - Swapping row and column declaration order was a codegen duplicate.
// - Fresh typed reconstruction below follows the map.cpp tile field names and
//   the executable's error-safe allocation and cleanup path.
// - A function-scope byte scratch improved the typed source by five positional
//   bytes; the remaining row-home mismatch stayed structural.
// - The executable stores tile object counts as words.  Keep the 0x18-byte tile
//   layout and the old-format bulk read with its post-read list reset.
// - Ten meaningful probes completed.  The clean typed source is retained in
//   scratch because the remaining drift is broad loop stack-home scheduling.

extern "C" void __cdecl rge_read(int, void*, int);
extern float save_game_version;
extern float old_map_cutoff;

class RGE_Map;

class RGE_Zone_Map_List {
public:
    void* zone_maps;
    int zone_map_num;
    RGE_Map* map;

    RGE_Zone_Map_List(int, RGE_Map*);
    ~RGE_Zone_Map_List();
};

class RGE_Unified_Visible_Map {
public:
    void load(int);
};

class RGE_Object_List {
public:
    void* list;
    short number_of_objects;
    char pad_06[2];
};

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char gap_0c[4];
    RGE_Object_List objects;
};

class RGE_Map {
public:
    char gap_00[4];
    RGE_Tile* map;
    long map_width;
    long map_height;
    char gap_10[0x8d7c];
    RGE_Tile** map_row_offset;
    char gap_8d90[0x28];
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    char gap_8dba[2];
    char gap_8dbc[8];
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;

    void new_map(long, long);
    void load_map(int);
};

void RGE_Map::load_map(int file)
{
    long local_10;
    long width;
    int x;
    long y;
    unsigned char value;

    rge_read(file, &local_10, 4);
    rge_read(file, &width, 4);
    this->new_map(local_10, width);

    RGE_Zone_Map_List* old_zones = this->map_zones;
    if (old_zones != 0) {
        delete old_zones;
    }

    RGE_Zone_Map_List* zones = new RGE_Zone_Map_List(file, this);
    this->map_zones = zones;

    rge_read(file, &this->map_visible_flag, 1);
    rge_read(file, &this->fog_flag, 1);

    if (!(save_game_version < old_map_cutoff)) {
        y = 0;
        if (this->map_height > 0) {
            do {
                RGE_Tile* tile = this->map_row_offset[y];
                x = 0;
                if (this->map_width > 0) {
                    do {
                        rge_read(file, tile, 2);
                        rge_read(file, &tile->screen_ypos, 2);
                        rge_read(file, &tile->tile_type, 1);

                        rge_read(file, &value, 1);
                        tile->terrain_type = (unsigned char)
                            (((value ^ tile->terrain_type) & 0x1f) ^
                             tile->terrain_type);
                        rge_read(file, &value, 1);
                        tile->terrain_type = (unsigned char)
                            ((value << 5) | (tile->terrain_type & 0x1f));

                        rge_read(file, &value, 1);
                        tile->border_type = (unsigned char)
                            (((value ^ tile->border_type) & 0x0f) ^
                             tile->border_type);
                        rge_read(file, &value, 1);
                        tile->last_drawn_as = 0;
                        tile->last_drawn_shape = 0xff;
                        tile->border_type = (unsigned char)
                            ((value << 4) | (tile->border_type & 0x0f));

                        tile->objects.list = 0;
                        tile->objects.number_of_objects = 0;
                        tile->draw_as = 0;
                        tile->draw_attribute = 0;
                        tile->last_drawn_shape2 = 0xff;

                        ++x;
                        ++tile;
                    } while (x < this->map_width);
                }
                ++y;
            } while (y < this->map_height);
        }
    } else {
        rge_read(file, this->map,
                 this->map_width * this->map_height * 0x18);
        y = 0;
        if (this->map_height > 0) {
            do {
                x = 0;
                if (this->map_width > 0) {
                    do {
                        this->map_row_offset[y][x].objects.list = 0;
                        ++x;
                    } while (x < this->map_width);
                }
                ++y;
            } while (y < this->map_height);
        }
    }

    this->unified_vis_map->load(file);
}
