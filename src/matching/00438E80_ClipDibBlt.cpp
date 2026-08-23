// VA: 00438E80 ClipDibBlt | Dib.cpp:280-366
// Attempt log:
// - baseline: real Win32 BITMAPINFO256/RECT surfaces and long-reference
//   parameters reproduced the complete clipping/scaling behavior and size.
// - reversed the two overlap-end predicates and used >= 1 for dimension
//   guards; this restored the original cmp polarity and exact bytes.

#include <windows.h>
#include "../../include/dib_context.h"

int __cdecl ClipDibBlt(BITMAPINFO256* dib, RECT* rect,
    LONG& x, LONG& y, LONG& width, LONG& height,
    LONG& src_x, LONG& src_y, LONG& src_width, LONG& src_height,
    int flip_x, int flip_y)
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;

    if (rect != 0) {
        left = rect->left;
        top = rect->top;
        right = rect->right + 1;
        bottom = rect->bottom + 1;
    } else {
        left = 0;
        top = 0;
        right = dib->bmiHeader.biWidth;
        bottom = dib->bmiHeader.biHeight;
    }

    if (bottom < 0)
        bottom = -bottom;
    right--;
    bottom--;

    if (x <= right && y <= bottom &&
        width + x - 1 >= left &&
        height + y - 1 >= top && width >= 1 && height >= 1) {
        LONG x_scale = (src_width << 8) / width;
        LONG y_scale = (src_height << 8) / height;

        if (x < left) {
            LONG delta = left - x;
            x = left;
            width -= delta;
            LONG scaled = (delta << 8) * x_scale >> 16;
            if (flip_x == 0)
                src_x += scaled;
            src_width -= scaled;
        }

        if (y < top) {
            LONG delta = top - y;
            y = top;
            height -= delta;
            LONG scaled = (delta << 8) * y_scale >> 16;
            if (flip_y == 0)
                src_y += scaled;
            src_height -= scaled;
        }

        LONG end = x + width;
        if (end - 1 > right) {
            LONG delta = end - right - 1;
            width -= delta;
            LONG scaled = (delta << 8) * x_scale >> 16;
            src_width -= scaled;
            if (flip_x != 0)
                src_x += scaled;
        }

        end = y + height;
        if (end - 1 > bottom) {
            LONG delta = end - bottom - 1;
            height -= delta;
            LONG scaled = (delta << 8) * y_scale >> 16;
            src_height -= scaled;
            if (flip_y != 0)
                src_y += scaled;
        }

        if (width >= 1 && height >= 1 && src_width >= 1 && src_height >= 1)
            return 1;
    }
    return 0;
}
