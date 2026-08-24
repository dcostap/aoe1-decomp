#ifndef SOUNDDRV_CANONICAL_TU
#include "../../include/sounddrv_context.h"
#endif

TSound_Driver::TSound_Driver(void* window, char* path) {
    this->init_vars();
    this->init(window, path);
}
