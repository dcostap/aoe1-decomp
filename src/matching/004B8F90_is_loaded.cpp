#include "../../include/shape_context.h"

int TShape::is_loaded() {
    if (this->shape || this->FShape) return 1;
    return 0;
}
