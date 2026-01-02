#pragma once
#include "../common.h"

class ostream_withassign {
public:

    ostream_withassign();
    ostream_withassign(streambuf* param_1);
    virtual ~ostream_withassign();
};

static_assert(sizeof(ostream_withassign) == 0x1, "ostream_withassign Size Mismatch");

