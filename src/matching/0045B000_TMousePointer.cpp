#include "../../include/mouseptr_context.h"

void operator_delete(void* ptr);

TMousePointer::~TMousePointer() {
    TShape* shape = this->Cursor_Shape;

    if (shape != 0) {
        shape->TShape::~TShape();
        operator_delete(shape);
        this->Cursor_Shape = 0;
    }
    this->delete_surfaces();
    MouseSystem = 0;
}
