#pragma once
#include "../types.h"

class TCommunications_Handler {
public:
    static int IsPaused(TCommunications_Handler* handler);

    char placeholder[6004];
};

static_assert(sizeof(TCommunications_Handler) == 6004, "TCommunications_Handler size mismatch");
