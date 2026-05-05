// 004BE090 TSpan_List_Manager::AddLine_Align (spanlist.cpp:961-1053, 337B)

class TSpan_List_Manager {
public:
    void AddSpan(int left, int right, int line);

    void AddLine_Align(int x1, int y1, int x2, int y2);
};

void TSpan_List_Manager::AddLine_Align(int x1, int y1, int x2, int y2)
{
    if (x1 == x2) {
        if (y1 > y2) { int t = y1; y1 = y2; y2 = t; }
        int a = x1 & 0xFFFFFFFC;
        int b = x1 | 3;
        while (y1 <= y2) { AddSpan(a, b, y1); y1++; }
    } else if (y1 == y2) {
        AddSpan(x1 & 0xFFFFFFFC, x2 | 3, y1);
    } else {
        if (x2 < x1) {
            int tx = x1; x1 = x2; x2 = tx;
            int ty = y1; y1 = y2; y2 = ty;
        }
        int dy = x2 - x1 + 1;
        int dx, step_y;
        if (y1 < y2) { dx = y2 - y1 + 1; step_y = 1; }
        else { dx = y1 - y2 + 1; step_y = -1; }
        if (dx >= dy) {
            int err = 0;
            int span_x = x1;
            int cur_x = x1;
            while (cur_x < x2) {
                err += dx;
                if (err >= dy) {
                    AddSpan(span_x & 0xFFFFFFFC, cur_x | 3, y1);
                    y1 += step_y;
                    err -= dy;
                    span_x = cur_x + 1;
                }
                cur_x++;
            }
            AddSpan(span_x & 0xFFFFFFFC, cur_x | 3, y1);
        } else {
            int err = 0;
            while (1) {
                AddSpan(x1 & 0xFFFFFFFC, x1 | 3, y1);
                if (x1 == x2) break;
                err += dy;
                if (err >= dx) { y1 += step_y; err -= dx; }
                x1++;
            }
        }
    }
}
