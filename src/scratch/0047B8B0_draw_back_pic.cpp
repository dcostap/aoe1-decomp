// 0047B8B0 TScrollBarPanel::draw_back_pic
// Source: Pnl_scbr.cpp lines 765-799, size 180 bytes
// Attempt log:
// first: 176 bytes (4 short). Non-virtual TShape methods, direct calls.
// second: precomputed temps didn't change register allocation.
// third: inline function args, back_frame local var — same result.
// fourth: mark base offset fields volatile to force call-argument evaluation order; worsened scheduling (180B but 15.6% diff), rolled back.
// fifth: field-first add expressions; no change from best 176B family.
// sixth: explicit x/y locals immediately before shape_draw; optimized away/no change.
// seventh: local shape pointer for draw call; no change.
// eighth-tenth: /Ob0, /O2-no-/Oy, /O1 flag probes; no improvement (/O1 153B), flags removed.
// eleventh: volatile cast on both coordinate member reads; worsened to 15.6%.
// twelfth: volatile cast only on x/base field_10; worsened early branch distances.
// thirteenth: volatile cast only on y/base field_0C; worsened early branch distances.
// GIVEUP: best source is 176B, 4 bytes shorter than original. Remaining issue is localized inner-loop register allocation/eval scheduling.
//   Original computes x as mov eax,[esi+10h]; mov ecx,ebx; add ecx,eax and y as mov ecx,[esi+0Ch]; mov edx,edi; add edx,ecx.
//   VC5 rebuild folds to mov ecx,[esi+10h]; add ecx,ebx and mov edx,[esi+0Ch]; add edx,edi.
//   Behavior is equivalent, but check_function cannot compare because the function is 4 bytes short; not proposing accepted_drift without a comparable 180B low-diff build.

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
                            this->field_0C + inner,
                            this->field_10 + outer,
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
