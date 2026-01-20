#pragma once
#include "common.h"

struct EHExceptionRecord {
};
static_assert(sizeof(EHExceptionRecord) == 0x1, "Size mismatch");
