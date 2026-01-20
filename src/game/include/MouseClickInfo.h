#pragma once
#include "common.h"

struct MouseClickInfo {
    int object_group;
    int self_action;
    int self_text_id;
    int gaia_action;
    int gaia_text_id;
    int ally_action;
    int ally_text_id;
    int neutral_action;
    int neutral_text_id;
    int enemy_action;
    int enemy_text_id;
};
static_assert(sizeof(MouseClickInfo) == 0x2C, "Size mismatch");
