// pnl_sld.cpp:162-176, 102 bytes
// attempt 1: 80 bytes, too small
// attempt 2: 71.6%, offsets shifted by vptr
// attempt 3: 59.8%, no vptr but offsets still wrong
// attempt 4: 12.7%, gap_00[0x0C] fixed base offsets
// attempt 5: 9.8%, gap padding between pairs fixed store offsets
// attempt 6: 8.8%, swapped min_left/min_right
// attempt 7: EXACT MATCH! key: min_right before span before min_left
//   forced correct instruction interleaving (add eax,2 between stores)
class TScrollBarPanel {
public:
    void set_rect(long, long, long, long);
    void calc_item_rects();
};

class THorizontalSliderPanel : public TScrollBarPanel {
public:
    char gap_00[0x0C];
    long field_0C;    // +0x0C
    long gap_10;
    long width;       // +0x14
    long height;      // +0x18
    char gap_1C[0x134 - 0x1C];
    long min_left;    // +0x134
    long min_right;   // +0x138
    long span;        // +0x13C
    char gap_140[0x164 - 0x140];
    long left1;       // +0x164
    char gap_168[4];
    long left2;       // +0x16C
    char gap_170[4];
    long right1;      // +0x174
    char gap_178[4];
    long right2;     // +0x17C

    void set_rect(long, long, long, long);
};

void THorizontalSliderPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    TScrollBarPanel::set_rect(param_1, param_2, param_3, param_4);
    long left = field_0C;
    long right = left + width - 1;
    left1 = left;
    left2 = left;
    right1 = right;
    right2 = right;
    min_right = left + 1;
    span = right - height + 2;
    min_left = left + 1;
    TScrollBarPanel::calc_item_rects();
}
