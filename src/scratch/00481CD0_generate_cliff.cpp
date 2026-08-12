// 00481CD0 RGE_RMM_Cliffs_Generator::generate_cliff()
// Source: rmm_clif.cpp lines 177-294
// Attempt log:
// - Replaced the old offset-only scaffold with the canonical random-map base,
//   RGE_Cliffs_Info fields, valid_cliff_sites Map_Stack, and typed RGE_Map
//   virtual surface established by the same-TU setup/generate callers.
// - The do/pop retry shape and vtable padding recover the 15-call set,
//   including map slots +0x10/+0x20; the best canonical source is 771 bytes
//   with a 0x38 frame and 15 aligned calls.
// - A six-variant local-order/retry lab found no size/frame/call-set eligible
//   improvement. Remaining structural drift is the 0x34 target frame and
//   start-sentinel/register/stack-home topology around Map_Stack cliff; no
//   register-forcing or opaque local scaffold was retained.
// - Restored the rolling start-point update proved by the executable after
//   each draw/invalidate segment; this moved the clean source to a 0x30 frame,
//   754 bytes, 15 aligned calls, and 92.80% shape (578 differing bytes).
// - The final row-base/column locals preserve the observed cell load order;
//   remaining drift is a four-byte frame gap plus early register scheduling.
// - A fresh pass swapped the byte-local declarations to test the target's
//   first_cliff [esp+13] and cliff_end_found [esp+12] homes; VC5 kept the
//   existing codegen and remained 577 differing bytes.
// - An infinite retry loop with an early empty-stack return was rejected: it
//   added one pop_stack call and 38 bytes. The original do/pop source remains
//   the best typed reconstruction, with all 15 calls aligned.
// - Restored distinct Map_Stack and float objects after finding the pinned
//   source used unsafe overlap casts. The typed form is authoritative even
//   though it leaves the known four-byte frame gap.

extern "C" int __cdecl debug_rand(char* file, int line);

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

struct RGE_Tile;

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0c(void);
    virtual void draw_line(long x1, long y1, long x2, long y2, long color, long width);
    virtual void vf18(void);
    virtual void vf1c(void);
    virtual void vf20(void);
    virtual void draw_rect(long x1, long y1, long x2, long y2, long color, long width);
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    void* parent;
    void* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void init_stack(Map_Stack* stack);
    Map_Stack* pop_stack(Map_Stack* head, long* x, long* y, float* cost);
    void push_stack(Map_Stack* head, long x, long y, float cost, float total_cost);
};

struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};

struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots hot_spots[99];
    long hot_spot_num;
};

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module {
public:
    virtual unsigned char generate(void);

    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;

    unsigned char check_for_valid_cliff_site(long direction, long* y,
                                              long* valid_height, long index);
    void invalidate_cliff_area(long x, long y, long spacing);
    void generate_cliff(void);
};

void RGE_RMM_Cliffs_Generator::generate_cliff(void) {
    long start_x = -1;
    long variance = this->info.cliff_size_variance;
    long start_y = -1;
    long y;
    long valid_height;
    long index;
    long this_cliff_size;
    long direction;
    long cost;
    unsigned char first_cliff;
    unsigned char cliff_end_found;
    Map_Stack cliff;
    cost = ((debug_rand((char*)"C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0xc4) *
                 variance * 2) / 0x7fff +
            this->info.average_cliff_size) - variance;
    first_cliff = 1;
    if (this->valid_cliff_sites.next == 0) {
        return;
    }
    if (cost < 3) {
        return;
    }

    float stack_cost;
    this->init_stack(&cliff);
    unsigned char* map_row;
    long column;
    do {
        this->pop_stack(&this->valid_cliff_sites, &y, &valid_height,
                        &stack_cost);
        map_row = this->search_map_rows[valid_height];
        column = y;
    } while (map_row[column] == 0 &&
             this->valid_cliff_sites.next != 0);
    if (map_row[column] == 0) {
        return;
    }

    index = this->search_map_rows[valid_height][y];
    this->push_stack(&cliff, y, valid_height, 0.0f, 0.0f);
    this->search_map_rows[valid_height][y] = 0;

    direction = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0xdd) * 4) / 0x7fff;
    this_cliff_size = 0;
    if (cost > 0) {
        do {
            cliff_end_found = 0;
            long turn = (debug_rand((char*)"C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0xe3) * 100) / 0x7fff;
            if (turn < 0x12) {
                if (direction < 1) {
                    direction = 3;
                } else {
                    direction--;
                }
            } else if (turn < 0x24) {
                if (direction < 3) {
                    direction++;
                } else {
                    direction = 0;
                }
            }

            if (this->check_for_valid_cliff_site(direction, &y, &valid_height, index) == 0 &&
                this->check_for_valid_cliff_site(direction + 1, &y, &valid_height, index) == 0 &&
                this->check_for_valid_cliff_site(direction - 1, &y, &valid_height, index) == 0 &&
                (first_cliff == 0 ||
                 this->check_for_valid_cliff_site(direction - 2, &y, &valid_height, index) == 0)) {
                cliff_end_found = 1;
            }
            first_cliff = 0;
            if (cliff_end_found != 0) {
                break;
            }
            this->push_stack(&cliff, y, valid_height, 0.0f, 0.0f);
            this->search_map_rows[valid_height][y] = 0;
            this_cliff_size++;
        } while (this_cliff_size < cost);
    }

    while (cliff.prev != 0) {
        this->pop_stack(&cliff, &y, &valid_height, &stack_cost);
        if (start_x == -1) {
            start_x = y;
            start_y = valid_height;
        }
        this->map->draw_line(start_x * 3 + 1, start_y * 3 + 1,
                             y * 3 + 1, valid_height * 3 + 1, 1, 0x10);
        this->map->draw_rect(start_x * 3 + 1, start_y * 3 + 1,
                             y * 3 + 1, valid_height * 3 + 1, 0, 0);
        start_x = y;
        start_y = valid_height;
        this->invalidate_cliff_area(y, valid_height, this->info.cliff_to_cliff_spacing);
    }
}
