// 0047B8B0 TScrollBarPanel::draw_back_pic
// Source: Pnl_scbr.cpp lines 765-799, size 180 bytes
// Attempt log:
// first: 176 bytes (4 short). Non-virtual TShape methods, direct calls.
// second: precomputed temps didn't change register allocation.
// third: inline function args, back_frame local var — same result.
// Left in scratch: 4 byte diff (2.2%) in inner loop body register allocation.
//   Inner loop body: original loads field_10 via eax (reusing after back_frame push)
//   and field_0C via ecx. Rebuilt loads field_10 directly to ecx, field_0C to edx.
//   Savings: mov eax,[esi+10h](3)+mov ecx,ebx(2)+add ecx,eax(2) vs mov ecx,[esi+10h](3)+add ecx,ebx(2)
//            and mov ecx,[esi+0Ch](3)+mov edx,edi(2)+add edx,ecx(2) vs mov edx,[esi+0Ch](3)+add edx,edi(2)
//   Rest of function (138 bytes) identical.

struct TShape {
    int shape_minmax(long* y_max, long* pic_hgt, long* x_min, long* y_min, int frame);
    int shape_draw(void* draw_area, long y, long x, int frame, int param5, int param6);
};

struct TScrollBarPanel {
    char gap_00[0x0C];       // +0x00 to +0x0B
    long field_0C;           // +0x0C (base y offset)
    long field_10;           // +0x10 (base x offset)
    long field_14;           // +0x14 (inner loop bound)
    long field_18;           // +0x18 (outer loop bound)
    char gap_1C[4];          // +0x1C
    void* field_20;          // +0x20 (draw area pointer)
    char gap_24[0xE4];       // +0x24 to +0x107
    TShape* button_pics;     // +0x108
    int back_frame;          // +0x10C

    void draw_back_pic();
};

void TScrollBarPanel::draw_back_pic() {
    if (this->button_pics != 0 && this->back_frame != -1) {
        long x_min, y_max, pic_hgt, y_min;
        this->button_pics->shape_minmax(&y_max, &pic_hgt, &x_min, &y_min, this->back_frame);

        int row_step = (x_min - y_max) + 1;
        int col_step = (y_min - pic_hgt) + 1;
        int outer = 0;

        if (this->field_18 >= 0) {
            do {
                int inner = 0;
                if (this->field_14 >= 0) {
                    do {
                        this->button_pics->shape_draw(
                            this->field_20,
                            inner + this->field_0C,
                            outer + this->field_10,
                            this->back_frame,
                            0,
                            0
                        );
                        inner += row_step;
                    } while (inner <= this->field_14);
                }
                outer += col_step;
            } while (outer <= this->field_18);
        }
    }
}
