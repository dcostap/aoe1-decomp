// 00546BB0 RGE_Zone_Map::do_zone_map_area
// Attempt log:
// 1: direct implementation from packet/decompiler with local map/tile layouts: same size 660, prologue/first 50 bytes exact; first drift is y held in EDI instead of original EDX.
// 2: compute cell pointer before tile pointer in neighbor blocks to test register allocation: much worse (edit diff 512); rolled back.
// 3: kept tile-before-cell best form; blocker is y parameter preserved in EDI instead of original EDX, causing broad register/layout drift after first 50 exact bytes.
// 4: same-size best is behaviorally close flood-fill but not accepted_drift-safe because drift spans all four neighbor arms.
// 5: no further safe source-shape lead found; leave in scratch.
// 6: TU-aware pass restored the canonical RGE_Tile bitfield and DAT_00577a20
//    double comparison; this improves the FPU/global surface and block alignment,
//    but the tile-row/cell-row register schedule still preserves y in EDI.
// Main-agent audit restored canonical polymorphic map ownership and retained
// named tile/zone-row flood-fill traversal.

struct RGE_Tile {
    short sx;
    short sy;
    unsigned char tile_type;
    unsigned char terrain_type : 5;
    unsigned char border_type : 4;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char objects[0x0c];
};
struct RGE_Map { virtual ~RGE_Map(); char pad04[4]; int map_width; int map_height; char pad10[0x8d8c-0x10]; RGE_Tile** map_row_offset; };
struct Zone_Queue;
extern double DAT_00577a20;
extern "C" void __cdecl zone_push(Zone_Queue** head, Zone_Queue** tail, long x, long y);
extern "C" unsigned char __cdecl zone_pop(Zone_Queue** head, Zone_Queue** tail, long* x, long* y);

class RGE_Zone_Map {
public:
    char pad0[0x408]; unsigned char** zone_map_rows; char pad40c[0x510-0x40c]; float* terrain_passability_rules; char pad514[4]; RGE_Map* map;
    void do_zone_map_area(long x, long y, unsigned char passable, unsigned char zone);
};

void RGE_Zone_Map::do_zone_map_area(long x, long y, unsigned char passable, unsigned char zone)
{
    Zone_Queue* zone_end = 0;
    Zone_Queue* zone_queue = 0;
    long max_x = this->map->map_width - 1;
    long max_y = this->map->map_height - 1;
    do {
        if (x > 0) {
            RGE_Tile* tile = this->map->map_row_offset[y] + x - 1;
            unsigned char* cell = this->zone_map_rows[y] + x - 1;
            if (*cell == 0xff) {
                int ok = (this->terrain_passability_rules[tile->terrain_type] > DAT_00577a20) ? 1 : 0;
                if (ok == (passable & 0xff)) {
                    *cell = zone;
                    zone_push(&zone_end, &zone_queue, x - 1, y);
                }
            }
        }
        if (y > 0) {
            RGE_Tile* tile = this->map->map_row_offset[y - 1] + x;
            unsigned char* cell = this->zone_map_rows[y - 1] + x;
            if (*cell == 0xff) {
                int ok = (this->terrain_passability_rules[tile->terrain_type] > DAT_00577a20) ? 1 : 0;
                if (ok == (passable & 0xff)) {
                    *cell = zone;
                    zone_push(&zone_end, &zone_queue, x, y - 1);
                }
            }
        }
        if (x < max_x) {
            RGE_Tile* tile = this->map->map_row_offset[y] + x + 1;
            unsigned char* cell = this->zone_map_rows[y] + x + 1;
            if (*cell == 0xff) {
                int ok = (this->terrain_passability_rules[tile->terrain_type] > DAT_00577a20) ? 1 : 0;
                if (ok == (passable & 0xff)) {
                    *cell = zone;
                    zone_push(&zone_end, &zone_queue, x + 1, y);
                }
            }
        }
        if (y < max_y) {
            RGE_Tile* tile = this->map->map_row_offset[y + 1] + x;
            unsigned char* cell = this->zone_map_rows[y + 1] + x;
            if (*cell == 0xff) {
                int ok = (this->terrain_passability_rules[tile->terrain_type] > DAT_00577a20) ? 1 : 0;
                if (ok == (passable & 0xff)) {
                    *cell = zone;
                    zone_push(&zone_end, &zone_queue, x, y + 1);
                }
            }
        }
    } while (zone_pop(&zone_end, &zone_queue, &x, &y));
}
