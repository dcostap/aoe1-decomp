#pragma once
#include "common.h"

struct Special_Events {
    long time_slice;
    long X_line_pos;
    long Y_line_pos;
    long intermediate_y_line_segment;
    uchar player_id;
    uchar player_color;
    uchar event;
    long pop_total;
    long interger_value_1;
    long interger_value_2;
    long start_x;
    long start_y;
    long start_txt_x1;
    long start_txt_y1;
    long start_txt_x2;
    long start_txt_y2;
    int text_length1;
    char text1[50];
    int text_length2;
    char text2[50];
    int icon_flag;
    Special_Events* next;
};
static_assert(sizeof(Special_Events) == 0xB0, "Size mismatch");
