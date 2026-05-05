// VA: 00445840 TDrawArea::DrawLine(int, int, int, int, unsigned char)
// PDB source: Drawarea.cpp lines 3817-3907 (348 bytes, 140 asm lines)
// Default flags
//
// Bresenham line drawing. No this/field access needed.
// Left in scratch: extensive register allocation and control-flow structure
// differences from the original VC5 version. Too complex for exact match.

extern void _ASMDraw_HLine(int x0, int x1, int y, unsigned int color);

struct TDrawArea {
    void DrawLine(int x1, int y1, int x2, int y2, unsigned char color);
};

void TDrawArea::DrawLine(int x1, int y1, int x2, int y2, unsigned char color) {
    int t_x2 = x2;
    int t_x1 = x1;
    if (t_x1 == t_x2) {
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
        return;
    }

    if (y1 == y2) {
        _ASMDraw_HLine(x1, x2, y1, (unsigned int)color);
        return;
    }

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
        int dy = y2 - y1 + 1;
        if (dy <= dx) {
            int y = y1;
            int last_x = x1;
            unsigned int c = (unsigned int)color;
            int err = 0;
            while (x1 < x2) {
                err += dy;
                if (err >= dx) {
                    _ASMDraw_HLine(last_x, x1, y, c);
                    y++;
                    err -= dx;
                    last_x = x1 + 1;
                }
                x1++;
            }
            _ASMDraw_HLine(last_x, x1, y, c);
        } else {
            unsigned int c = (unsigned int)color;
            int err = 0;
            int x = x1;
            for (;;) {
                _ASMDraw_HLine(x, x, y1, c);
                if (y1 == y2) break;
                y1++;
                err += dx;
                if (err >= dy) {
                    x++;
                    err -= dy;
                }
            }
        }
    } else {
        int dy = y1 - y2 + 1;
        if (dy <= dx) {
            int y = y1;
            int last_x = x1;
            unsigned int c = (unsigned int)color;
            int err = 0;
            while (x1 < x2) {
                err += dy;
                if (err >= dx) {
                    _ASMDraw_HLine(last_x, x1, y, c);
                    y--;
                    err -= dx;
                    last_x = x1 + 1;
                }
                x1++;
            }
            _ASMDraw_HLine(last_x, x1, y, c);
        } else {
            unsigned int c = (unsigned int)color;
            int err = 0;
            int x = x1;
            for (;;) {
                _ASMDraw_HLine(x, x, y1, c);
                if (y1 == y2) break;
                y1--;
                err += dx;
                if (err >= dy) {
                    x++;
                    err -= dy;
                }
            }
        }
    }
}
