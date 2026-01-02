#pragma once
#include "../common.h"

class istream_withassign {
public:

    istream_withassign();
    istream_withassign(streambuf* param_1);
    virtual ~istream_withassign();
};

static_assert(sizeof(istream_withassign) == 0x1, "istream_withassign Size Mismatch");

