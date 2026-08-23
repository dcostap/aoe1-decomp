#include "../../include/shape_context.h"

long TShape::shape_count(void) {
    if (Check_shape(-1, "RGL_shape_count") != 0) {
        return 0;
    }
    if (this->FShape != 0) {
        return this->FShape->Num_Shapes;
    }
    return this->head->shape_num;
}
