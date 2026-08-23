// 00486210 RGE_RMM_Object_Generator::remove_area_from_lists
// Source: rmm_obj.cpp lines 230-251. 154 bytes. __thiscall, ret 0Ch.

#include "..\..\include\rmm_obj_context.h"

void RGE_RMM_Object_Generator::remove_area_from_lists(long left, long right, long y) {
    long x_start = left - y;
    long y_start = right - y;
    long x_end = y + left;
    long y_end = y + right;

    if (x_start < 0)
        x_start = 0;
    if (y_start < 0)
        y_start = 0;

    if (x_end >= this->width)
        x_end = this->width - 1;
    if (y_end >= this->height)
        y_end = this->height - 1;

    for (long cur_y = y_start; cur_y <= y_end; cur_y++) {
        if (x_start <= x_end) {
            long offset = x_start * 24;
            long count = x_end - x_start + 1;
            do {
                this->remove_stack_node((Map_Stack*)((char*)this->map_rows[cur_y] + offset));
                offset += 24;
                count--;
            } while (count != 0);
        }
    }
}
