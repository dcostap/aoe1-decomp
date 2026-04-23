class ShapeHeader {
public:
    char gap_00[0x04];
    long Num_Shapes;
};

class TShape {
public:
    char gap_00[0x10];
    ShapeHeader* head;
    char gap_14[0x04];
    ShapeHeader* FShape;

    unsigned char Check_shape(long param, const char* name);
    long shape_count(void);
};

long TShape::shape_count(void) {
    ShapeHeader* shape;

    if (Check_shape(-1, "RGL_shape_count") != 0) {
        return 0;
    }
    shape = this->FShape;
    if (shape == 0) {
        shape = this->head;
    }
    return shape->Num_Shapes;
}
