// VA: 00445840 TDrawArea::DrawLine(int, int, int, int, unsigned char)
// PDB source: Drawarea.cpp lines 3817-3907 (348 bytes, 140 asm lines)
// Default flags
//
// Bresenham line drawing. No this/field access needed.
// Attempt log:
// - Baseline: the typed parameter ownership/algorithm emitted 10 helper calls
//   instead of the oracle's 5 and used the wrong C++ helper linkage.
// - Common y-direction selection plus the C ABI fixed the call target and
//   shared shallow/steep topology; a steep do/while body was required because
//   VC5 duplicated calls for the call-first/break and comma-condition forms.
// - Vertical endpoint locals delayed the original y loads and improved the
//   prologue; saved endpoint locals and a redundant post-swap guard were worse.
// - Best checked source below: 348-byte output, 5/5 ordered calls, 83.80%
//   shape, 55.71% exact-block coverage, 310 differing bytes. Remaining gap is
//   broad VC5 register/block scheduling beginning in the prologue; leave this
//   natural reconstruction in scratch rather than retain codegen scaffolding.
// - Fresh pass: direct vertical parameter mutation worsened the source. A
//   saved x endpoint and a pre-orientation x-start were duplicate or worse.
//   Reusing x1 as the y-step collapsed the function and was restored.
// - Fresh pass: reversing the equal-endpoint compare was neutral. Spelling
//   the shallow gate as dx >= dy improved shape to 84.51% but not bytes.
//   The clean typed source remains best after nine meaningful probes.
// - Fresh pass: lifting the shared Bresenham error declaration before the
//   orientation branch was a natural test for the oracle's EBX error/EBP x2
//   coloring; VC5 emitted duplicate bytes, so the clean source was restored.
// - Fresh pass: reversing the vertical endpoint declaration order tested the
//   first-hunk register coloring; VC5 worsened to 312 differing bytes and
//   83.10% shape, so the natural declaration order was restored.
// - Fresh pass: hoisting all natural endpoint and Bresenham locals to function
//   scope produced identical bytes, so it did not explain the first block.
// - Fresh pass: moving the steep termination test directly after the helper
//   improved block shape but made VC5 emit a sixth helper call; both an
//   explicit break and return were rolled back. The clean five-call source is
//   retained; the remaining lead is the original parameter/register basin.

extern "C" void __cdecl _ASMDraw_HLine(int x0, int x1, int y, unsigned int color);

struct TDrawArea {
    void DrawLine(int x1, int y1, int x2, int y2, unsigned char color);
};

void TDrawArea::DrawLine(int x1, int y1, int x2, int y2, unsigned char color) {
    if (x1 == x2) {
        int y_start = y1;
        int y_end = y2;
        if (y_start > y_end) {
            int t = y_start;
            y_start = y_end;
            y_end = t;
        }
        unsigned int c = (unsigned int)color;
        do {
            _ASMDraw_HLine(x1, x2, y_start, c);
            y_start++;
        } while (y_start <= y_end);
    } else if (y1 == y2) {
        _ASMDraw_HLine(x1, x2, y1, (unsigned int)color);
    } else {
        int step;
        int dy;

        if (x2 < x1) {
            int t = x2;
            x2 = x1;
            x1 = t;
            t = y2;
            y2 = y1;
            y1 = t;
        }

        int dx = x2 - x1 + 1;
        if (y1 < y2) {
            dy = y2 - y1;
            step = 1;
        } else {
            dy = y1 - y2;
            step = -1;
        }
        ++dy;

        if (dy <= dx) {
            int error = 0;
            int line_start = x1;
            for (; x1 < x2; ++x1) {
                error += dy;
                if (error >= dx) {
                    _ASMDraw_HLine(line_start, x1, y1, (unsigned int)color);
                    y1 += step;
                    error -= dx;
                    line_start = x1 + 1;
                }
            }
            _ASMDraw_HLine(line_start, x1, y1, (unsigned int)color);
        } else {
            int error = 0;
            do {
                _ASMDraw_HLine(x1, x1, y1, (unsigned int)color);
                error += dx;
                if (error >= dy) {
                    ++x1;
                    error -= dy;
                }
                y1 += step;
            } while (y1 != y2);
        }
    }
}
