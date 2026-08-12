// VA: 00510110 make_new_cliff (399B)
// tmap.cpp
//
// Attempt log:
// baseline: clean typed reconstruction from the make_new_cliff packet and
// the exact RGE_Player::make_new_object / check_destructables ABIs.
// prior pass: direct full table indexing, curr_player tile ownership, local
// declaration/lifetime orders, coordinate locals, and top-level loop seeds
// changed only VC5 structural families; the clean typed family remained
// nonexact but retained the correct aggregate-parameter homes.
// fresh baseline: 384B / 368 differing bytes, with all calls and frame data
// aligned.
// probe: id2 > -1 restored the oracle's early EDI=-1 seed and reduced the
// diff to 211B, but shifted the aggregate parameter homes by four bytes.
// probe: canonical polymorphic map/world/player/object declarations and the
// proven diam_tile_list (+0x6c) surface were codegen-neutral.
// probe: a positive id>=0 success guard with a cold zero return recovered the
// original 399B size and far failure block, reducing the diff to 36B.
// probe: explicit weighted table-index terms restored the info0/info1 load
// order and improved the best result to 33B / 94.24% resync similarity.
// left in scratch: exact calls, frame, size, CFG, and preamble are recovered;
// remaining localized drift is the selected-facet/result stack-home coloring
// ([esp+18]/[esp+14]) and its cold return epilogue.
// tu-tmap-510110 probe 1: moving the initialized result pointer before the
// coordinate locals was codegen-neutral.
// tu-tmap-510110 probe 2: reversing the negative table-arm assignment order
// widened the mismatch to 227 bytes; restored the clean source.
// tu-tmap-510110 probe 3: swapping typed id/facet declaration order was a
// codegen duplicate; the localized 33-byte stack-home drift remains.
// sa7b8c14ff-cliff probe: explicit cold return 0, uninitialized or scoped
// result declarations, result/facet declaration reorders, and a direct call
// initializer were all codegen duplicates.
// sa7b8c14ff-cliff probe: named y_tile/x_tile locals caused a 382-byte
// structural mismatch; restored the clean inline-coordinate source.
// sa7b8c14ff-cliff final: retain the 399-byte typed source. The remaining
// 33-byte drift is limited to facet/result stack-home coloring and the cold
// return epilogue. No evidence-backed natural lead remains in this pass.

struct TRIBE_Cliff_Info {
    long info[4];
};

struct CliffMasterEntry {
    long id;
    long facet;
    long id2;
    long facet2;
    long info[4];
    float offset_x;
    float offset_y;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x31];
    unsigned char facet;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    void add_node(int x, int y);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual RGE_Static_Object* make_new_object(long id, float x, float y,
                                                float z, int unused);
    char gap_04[0x1E];
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    char gap_3C[0x04];
    void* doppleganger_creator;
    char* name;
    char gap_48[0x04];
    short attribute_num;
    char gap_4E[0x02];
    float* attributes;
    char gap_54[0x04];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x3C];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class TRIBE_World : public RGE_Game_World {
public:
    void check_destructables(short player_id, short master_id,
                             float x, float y, unsigned char flag);
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x8DBC];
    TRIBE_World* game_world;
};

class TRIBE_Map : public RGE_Map {
public:
    char gap_8DC4[0x34];
    CliffMasterEntry cliff_master_table[1];

    RGE_Static_Object* make_new_cliff(long x, long y,
                                      TRIBE_Cliff_Info info);
};

extern int __cdecl debug_rand(char* file, int line);

RGE_Static_Object* TRIBE_Map::make_new_cliff(long x, long y,
                                              TRIBE_Cliff_Info info)
{
    int table_index = info.info[0] * 16 + info.info[1] * 4 + info.info[2];
    int cliff_index = table_index * 4 + info.info[3] + 0x55;
    long facet;
    float x_pos = (float)(x * 3) +
        this->cliff_master_table[cliff_index].offset_x;
    float y_pos = (float)(y * 3) +
        this->cliff_master_table[cliff_index].offset_y;
    RGE_Static_Object* new_cliff = 0;
    long id;

    if (this->cliff_master_table[cliff_index].id2 > -1 &&
        debug_rand((char*)"C:\\msdev\\work\\age1_x1\\tmap.cpp", 0x221) * 2 > 0x7fff) {
        id = this->cliff_master_table[cliff_index].id2;
        facet = this->cliff_master_table[cliff_index].facet2;
    } else {
        id = this->cliff_master_table[cliff_index].id;
        facet = this->cliff_master_table[cliff_index].facet;
    }

    if (id >= 0) {
        new_cliff = this->game_world->players[0]->make_new_object(
            id, x_pos, y_pos, 0.0f, 0);

        for (long tile_offset = -1; tile_offset < 2; ++tile_offset) {
            for (long j = -1; j < 2; ++j) {
                this->game_world->players[this->game_world->curr_player]
                    ->diam_tile_list.add_node(
                    (int)(tile_offset + (long)(x_pos)),
                    (int)(j + (long)(y_pos)));
            }
        }

        if (new_cliff != 0)
            new_cliff->facet = (unsigned char)facet;

        this->game_world->check_destructables(0, (short)id, x_pos, y_pos, 1);
        return new_cliff;
    }

    return new_cliff;
}
