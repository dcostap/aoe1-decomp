// 00481CD0 RGE_RMM_Cliffs_Generator::generate_cliff
// Attempt log:
// try 1: reconstructed from asm with stack locals, random choice loop, direction update, valid-site checks, drawing calls.
// try 2: first compile exact byte size but frame 0x24 vs original 0x34; broad local-slot/register drift.
// try 3: verified debug_rand lines 196/221/227 from asm pushes 0xC4/0xDD/0xE3; kept.
// try 4: modeled start_x/start_y as long initialized to -1 to force ebp/edi sentinels; compiler still homes to stack too early.
// try 5: kept direct member offsets +0x38/+0x3c/+0x24/+0x500 per asm; no type-layout blocker found.
// try 6: modeled initial pop retry as do/while; call sequence present but local offsets differ.
// try 7: modeled first_cliff/cliff_end_found as unsigned char; byte stores present but stack slots shifted.
// try 8: expressed direction turn thresholds as <18/<36 to match compare constants; region remains structurally close but shifted.
// try 9: expressed four check_for_valid_cliff_site calls in natural || chain; call set/stack cleanup match family, register scheduling drifts.
// try 10: modeled drawing calls as virtual calls at +0x10/+0x20 with scale (coord*3+1); late block recognizable but not exact.
// left in scratch: behavior/call set are reconstructed, but VC5 local-frame topology is wrong (0x24 vs 0x34) causing broad positional drift; not accepted_drift-safe.

extern "C" int __cdecl debug_rand(char*, int);
static char rmm_clif_cpp[] = "C:\\msdev\\work\\age1_x1\\rmm_clif.cpp";

struct DrawIface { virtual void f0(); virtual void f4(); virtual void f8(); virtual void fC(); virtual void draw_line(int,int,int,int,int,int); virtual void f18(); virtual void f1c(); virtual void draw_rect(int,int,int,int,int,int); };

class RGE_RMM_Cliffs_Generator {
public:
    char gap0[0x0c];
    DrawIface* draw;
    char gap10[0x24-0x10];
    unsigned char** valid_rows;
    char gap28[0x38-0x28];
    int cliff_min_length;
    int cliff_max_length;
    int cliff_terrain_spacing;
    int cliff_color;
    char gap48[0x4f0-0x48];
    char valid_cliff_sites;
    char gap4f1[0x500-0x4f1];
    int cliff_stack_count;

    void init_stack(void*);
    void* pop_stack(void*, long*, long*, long*);
    void push_stack(void*, int, int, float, float);
    unsigned char check_for_valid_cliff_site(long, long*, long*, long);
    void invalidate_cliff_area(long, long, long);
    void generate_cliff();
};

void RGE_RMM_Cliffs_Generator::generate_cliff()
{
    long x;
    long y;
    long valid_height;
    long cliff;
    long cost;
    unsigned char first_cliff;
    unsigned char cliff_end_found;
    long dir;
    long start_x;
    long start_y;

    start_y = -1;
    start_x = -1;
    cost = this->cliff_min_length + ((debug_rand(rmm_clif_cpp, 196) * this->cliff_max_length * 2) / 32767) - this->cliff_max_length;
    first_cliff = 1;
    if (this->cliff_stack_count == 0 || cost < 3) return;

    this->init_stack(&cliff);
    do {
        this->pop_stack(&this->valid_cliff_sites, &x, &valid_height, &cliff);
        if (this->valid_rows[valid_height][x] != 0) break;
        if (this->cliff_stack_count == 0) return;
    } while (1);

    y = valid_height;
    dir = this->valid_rows[valid_height][x];
    this->push_stack(&y, x, valid_height, 0, 0);
    this->valid_rows[valid_height][x] = 0;
    dir = (debug_rand(rmm_clif_cpp, 221) * 4) / 32767;

    long i = 0;
    if (cost > 0) {
        do {
            cliff_end_found = 0;
            long r = (debug_rand(rmm_clif_cpp, 227) * 100) / 32767;
            if (r < 18) {
                if (dir <= 0) dir = 3;
                else dir--;
            } else if (r < 36) {
                if (dir >= 3) dir = 0;
                else dir++;
            }
            if (this->check_for_valid_cliff_site(dir, &x, &valid_height, y) ||
                this->check_for_valid_cliff_site(dir + 1, &x, &valid_height, y) ||
                this->check_for_valid_cliff_site(dir - 1, &x, &valid_height, y) ||
                (first_cliff && this->check_for_valid_cliff_site(dir - 2, &x, &valid_height, y))) {
            } else {
                cliff_end_found = 1;
            }
            first_cliff = 0;
            if (cliff_end_found) break;
            this->push_stack(&y, x, valid_height, 0, 0);
            this->valid_rows[valid_height][x] = 0;
            i++;
        } while (i < cost);
    }

    if (this->cliff_stack_count == 0) return;
    do {
        this->pop_stack(&cliff, &x, &y, &valid_height);
        if (start_y == -1) {
            start_y = y;
            start_x = x;
        }
        this->draw->draw_line(start_y * 3 + 1, start_x * 3 + 1, y * 3 + 1, x * 3 + 1, 1, 16);
        this->draw->draw_rect(start_y * 3 + 1, start_x * 3 + 1, valid_height * 3 + 1, x * 3 + 1, 0, 0);
        this->invalidate_cliff_area(x, y, this->cliff_color);
    } while (this->cliff_stack_count != 0);
}
