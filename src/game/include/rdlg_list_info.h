#pragma once
#include "common.h"

struct rdlg_list_info {
    char text[100];
    short id;
};
static_assert(sizeof(rdlg_list_info) == 0x66, "Size mismatch");
