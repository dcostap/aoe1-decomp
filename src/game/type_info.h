#pragma once
#include "../common.h"

class type_info {
public:

    virtual ~type_info();
    virtual int operator==(type_info* param_1);
    virtual int operator!=(type_info* param_1);
    virtual int before(type_info* param_1);
    virtual char* raw_name();
    type_info(type_info* param_1);
    virtual type_info* operator=(type_info* param_1);
};

static_assert(sizeof(type_info) == 0x1, "type_info Size Mismatch");

