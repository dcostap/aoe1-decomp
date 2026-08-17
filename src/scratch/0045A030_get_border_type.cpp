// VA 0045A030 RGE_Map::get_border_type
// map.cpp:2845-3012
// Attempt log:
// 1: Direct natural reconstruction from packet: neighbor terrain sampling, check_for_border calls, terrain-border lookup and edge code selection.
// 2: Modeled map layout facts used by asm: width +8, height +0xC, row table +0x8D8C, tile stride 24, terrain byte at +5 masked by 0x1F, output byte at +6.
// 3: Modeled eight neighbor samples in original order (left/right/top/bottom/corners by row +/-1 and offset +/-24), including boundary fallback to current terrain.
// 4: Added eight check_for_border(current,&neighbor) calls in the original order.
// 5: Added all-same-neighbor early zero-out path.
// 6: Added border lookup as raw table at this+0x14A + current*408, neighbor index*2, matching original address math better than an oversized C array.
// 7: Added border validity checks: 0xFFFF, negative, >=16, and terrain-enabled byte at this+0x338C + border*1440.
// 8: Added special word [edx+0x392A] == 1 case by composing low border nibble with bitmask of four cardinal neighbors.
// 9: Added normal edge selection ordering for 1,2,3,4,9,10,11,12,5,6,7,8 and final zero-out fallback.
// 10: Default /O2 /Oy compiles but is size-short: configured 1115 exceeds rebuilt .text 848. Source is behaviorally broad but too high-level/optimized relative to original stack-slot-heavy VC5 shape.
// 11: Probed /Od: exact size 1115 but broad wrong basin from offset 0 (91.7489% positional); removed flag.
// 12: Probed /O2 /Oy /Og-: exact size 1115 but same broad wrong basin from offset 0; removed flag.
// 13: Tried removing helper terrain_at and inlining row[offset] loads; default shrank further (944 -> 848), confirming original likely needs source-shaped stack-slot/parameter reuse rather than helper abstraction.
// 14: Replaced raw displacement table and gap-only class with the period-plausible RGE_Map/RGE_Tile/RGE_Tile_Set/RGE_Border_Set surfaces. The named borders[] access is the canonical owner of +0x14A and +0x338C, while the real virtual-prefix/map layout preserves +0x8/+0xC/+0x8D8C.
// 15: Reordering persistent row/current declarations was a codegen duplicate.
// 16: Self-alias, split-boundary, nested/assignment-carry, and shared-goto variants were rejected: they were unchanged or expanded the function to 1509-1568 bytes.
// 17: Promoting x to an explicit int cursor moved its stack home closer (986 bytes, diff 1016) but still left the saved-this/row register basin and byte-local homes wrong; full virtual-prefix context changed only one byte.
// 18: Restored the cleaner canonical typed reconstruction as the best current source. Remaining blocker is structural VC5 register/local-home allocation (original this=EDI, rows=ESI, x home +2C, y=EBP; rebuilt this=ESI, rows=EBP and different byte homes), not calls or layout.
// 19: Re-tested separate typed x/y bounds guards from the exact get_tile_type donor; VC5 emitted the same code, so restored the canonical combined guard.
// 20: In this claim, moved named x/y cursors before split guards; prologue and frame basin worsened, so restored clean source.
// 21: Reused x/y parameter homes for terrain bytes; frame shrank and CFG moved, but positional diff widened, so restored.
// 22: Swapped max-local declaration order; emitted code was unchanged.
// 23: Initialized an outer row cursor before the column cursor; size shrank and first-block structure worsened, so restored.
// 24: Put promoted cursor assignments in the bounds predicate; diff improved to 994, but code size fell to 944 and the source became decompiler-shaped, so restored.
// 25: Final claim state retains the canonical typed source. Calls and frame match; remaining gap is saved-this/row register and local-home allocation.
// 26: This claim tested early x assignment, declaration order, bound operand order, cached table pointers, current-int materialization, signed bytes, and current-tile address forms. Most were duplicates or worse.
// 27: Keeping the eighth neighbor as a separate unsigned-char local instead of reusing the x cursor reduced positional diff from 1014 to 673 bytes and kept all eight call sites at the original offsets. This is the current best source shape.
// 28: Volatile all-same reads and a volatile border-table view produced extra frames or code, so they are rejected as metric-only steering.
// 29: Cardinal border preload locals restored the full normal decision CFG but grew the function to 1324 bytes. The simpler direct typed chain remains the clean source.

struct RGE_Tile {
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
    char gap_0C[0x0C];
};

struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

class RGE_Sound;
class TShape;

class RGE_Tile_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char map_lt_cliff_color;
    unsigned char map_rt_cliff_color;
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    unsigned char obj_placement_flag[30];
    short num_obj_type;
    unsigned char pad_end[2];
};

class RGE_Border_Set {
public:
    unsigned char loaded;
    unsigned char random;
    char name[13];
    char pict_name[13];
    long resource_id;
    TShape* shape;
    RGE_Sound* sound;
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    unsigned char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    unsigned char frame_changed;
    unsigned char drawn;
    RGE_TOB_Picts borders[19][12];
    unsigned char draw_tile;
    unsigned char pad_0;
    short underlay_terrain;
    short border_style;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size tilesizes[19];
    unsigned char pad_8A[2];
    RGE_Tile_Set terrain_types[32];
    RGE_Border_Set border_types[16];
    RGE_Tile** map_row_offset;
    short num_terrain;
    short num_borders;
    short max_terrain;
    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    short cur_row;
    short cur_col;
    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;
    unsigned char any_frame_change;
    unsigned char pad_8D[3];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    unsigned char pad_8DBA[2];
    void* random_map;
    void* game_world;
    void* map_zones;
    void* unified_vis_map;
    void* unit_manager;

    void check_for_border(unsigned char current, unsigned char* other);
    void get_border_type(short x, short y);
};

void RGE_Map::get_border_type(short x, short y)
{
    unsigned char ter_top_lft;
    unsigned char ter_lft;
    unsigned char ter_rgt;
    unsigned char ter_bot;
    unsigned char tile;
    unsigned char ter_bot_lft;
    unsigned char ter_bot_rgt;
    int yMax;
    int xMax;
    int xi;
    unsigned char ter_top;
    unsigned char ter_final;

    if (x < 0 || x >= this->map_width || y < 0 || y >= this->map_height) {
        return;
    }

    RGE_Tile** rows = this->map_row_offset;
    xi = x;
    RGE_Tile* cur = rows[y] + xi;
    ter_top_lft = cur->terrain_type & 0x1f;

    if (y > 0) ter_lft = rows[y - 1][xi].terrain_type & 0x1f; else ter_lft = ter_top_lft;
    yMax = this->map_height - 1;
    if (y < yMax) tile = rows[y + 1][xi].terrain_type & 0x1f; else tile = ter_top_lft;
    if (x > 0) ter_rgt = rows[y][xi - 1].terrain_type & 0x1f; else ter_rgt = ter_top_lft;
    xMax = this->map_width - 1;
    if (xi < xMax) ter_bot = rows[y][xi + 1].terrain_type & 0x1f; else ter_bot = ter_top_lft;
    if (y > 0 && x > 0) ter_bot_lft = rows[y - 1][xi - 1].terrain_type & 0x1f; else ter_bot_lft = ter_top_lft;
    if (y > 0 && xi < xMax) ter_top = rows[y - 1][xi + 1].terrain_type & 0x1f; else ter_top = ter_top_lft;
    if (y < yMax && x > 0) ter_bot_rgt = rows[y + 1][xi - 1].terrain_type & 0x1f; else ter_bot_rgt = ter_top_lft;
    if (y < yMax && xi < xMax) ter_final = rows[y + 1][xi + 1].terrain_type & 0x1f; else ter_final = ter_top_lft;

    check_for_border(ter_top_lft, &ter_lft);
    check_for_border(ter_top_lft, &tile);
    check_for_border(ter_top_lft, &ter_rgt);
    check_for_border(ter_top_lft, &ter_bot);
    check_for_border(ter_top_lft, &ter_bot_lft);
    check_for_border(ter_top_lft, &ter_top);
    check_for_border(ter_top_lft, &ter_bot_rgt);
    check_for_border(ter_top_lft, &ter_final);

    if (ter_lft == ter_top_lft && tile == ter_top_lft && ter_rgt == ter_top_lft && ter_bot == ter_top_lft &&
        ter_bot_lft == ter_top_lft && ter_top == ter_top_lft && ter_bot_rgt == ter_top_lft && ter_final == ter_top_lft) {
        cur->border_type = 0;
        return;
    }

    short border = this->terrain_types[ter_top_lft].borders[(unsigned char)ter_lft];
    if (border == -1 || border < 0 || border >= 16 || this->border_types[border].loaded == 0) {
        cur->border_type = 0;
        return;
    }

    unsigned char edge;
    if (this->border_types[border].border_style == 1) {
        edge = 0;
        if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_lft] == border) edge |= 1;
        if (this->terrain_types[ter_top_lft].borders[(unsigned char)tile] == border) edge |= 2;
        if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_rgt] == border) edge |= 4;
        if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_bot] == border) edge |= 8;
        cur->border_type = (unsigned char)((border & 0xf) | (edge << 4));
        return;
    }

    if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_lft] == border &&
        this->terrain_types[ter_top_lft].borders[(unsigned char)ter_rgt] == border) {
        edge = 1;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_lft] == border &&
               this->terrain_types[ter_top_lft].borders[(unsigned char)ter_bot] == border) {
        edge = 2;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)tile] == border &&
               this->terrain_types[ter_top_lft].borders[(unsigned char)ter_rgt] == border) {
        edge = 3;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)tile] == border &&
               this->terrain_types[ter_top_lft].borders[(unsigned char)ter_bot] == border) {
        edge = 4;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_lft] == border) {
        edge = 9;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)tile] == border) {
        edge = 10;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_rgt] == border) {
        edge = 11;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_bot] == border) {
        edge = 12;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_bot_lft] == border) {
        edge = 5;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_top] == border) {
        edge = 6;
    } else if (this->terrain_types[ter_top_lft].borders[(unsigned char)ter_bot_rgt] == border) {
        edge = 7;
    } else if (this->terrain_types[ter_top_lft].borders[ter_final] == border) {
        edge = 8;
    } else {
        cur->border_type = 0;
        return;
    }
    cur->border_type = (unsigned char)((border & 0xf) | (edge << 4));
}
