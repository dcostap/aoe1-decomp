#pragma once
#include "common.h"

struct TextNode {
    char* text;
    char* text2;
    long id;
    TextNode* next_node;
};
static_assert(sizeof(TextNode) == 0x10, "Size mismatch");
