// 00486180 RGE_RMM_Object_Generator::set_search_area
// Source: rmm_obj.cpp lines 206-226. 134 bytes. __thiscall, ret 10h.
// Attempt log:
// - Earlier natural loop forms produced a 112-byte too-short window from register/scheduling differences.
// - 2026-05-10 StarryZephyr pass: rewrote to reuse incoming parameter slots as end_y/current_y, direct row reloads.
//   This recovered 134-byte size and 111 edit-equal bytes, but remains shifted by early save/mov ordering (`mov esi,ecx`
//   before `push edi`), EAX/EBP end_y selection, and outer-loop reload order. No accepted_drift.

class RGE_RMM_Object_Generator {
public:
    char gap_00[0x14];
    long map_width;
    long map_height;
    char gap_1C[0x08];
    unsigned char** search_map_rows;

    void set_search_area(long x, long y, long radius, unsigned char fill);
};

void RGE_RMM_Object_Generator::set_search_area(long x, long y, long radius, unsigned char fill)
{
    long start_x = x - radius;
    long start_y = y - radius;
    long end_x = x + radius;
    long end_y = radius + y;

    if (start_x < 0)
        start_x = 0;
    if (start_y < 0)
        start_y = 0;
    if (end_x >= this->map_width)
        end_x = this->map_width - 1;
    if (end_y >= this->map_height)
        end_y = this->map_height - 1;

    for (y = start_y; y <= end_y; ++y) {
        if (start_x <= end_x) {
            long cur_x = start_x;
            do {
                ++cur_x;
                this->search_map_rows[y][cur_x - 1] = fill;
            } while (cur_x <= end_x);
        }
    }
}
